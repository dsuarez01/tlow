#pragma once

#include <memory>
#include <new>
#include <type_traits>

namespace tlow::runtime {

// see: https://medium.com/@sgn00/high-performance-memory-management-arena-allocators-c685c81ee338
// preserves strong guarantee
class Arena {
public:

    explicit Arena(std::size_t sz) 
        : buf_(static_cast<char*>(::operator new(sz))), 
          capacity_(sz) {}

    ~Arena() {
        call_dtors();
        ::operator delete(buf_);
    }

    Arena(const Arena&) = delete;
    Arena& operator=(const Arena&) = delete;

    Arena(Arena&&) = delete;
    Arena& operator=(Arena&&) = delete;

    void* alloc_raw(std::size_t sz, std::size_t align) {
        auto [ptr, new_offset] = alloc(offset_, sz, align);
        offset_ = new_offset;
        return ptr;
    }

    template <typename T, typename... Args>
    T* create(Args&&... args) {
        auto [ptr, cur_offset] = alloc(offset_, sizeof(T), alignof(T));

        // trivially destructible: no dtor node, else yes
        if constexpr (std::is_trivially_destructible_v<T>) {
            T* obj = new (ptr) T(std::forward<Args>(args)...);
            offset_ = cur_offset;
            return obj;
        } else {
            auto [dtor_node_ptr, fin_offset] = alloc(cur_offset, sizeof(DtorNode), alignof(DtorNode));
            T* obj = new (ptr) T(std::forward<Args>(args)...);

            auto dtor_fcn = [](void* p) { static_cast<T*>(p)->~T(); };
            DtorNode* new_node = new (dtor_node_ptr) DtorNode{dtor_fcn, tail_, obj};
            
            // commit changes only after allocations successful (strong guarantee)
            tail_ = new_node;
            offset_ = fin_offset;
            return obj;
        }

    }

    void reset() {
        call_dtors();
        offset_ = 0;
    }

private:

    // reverse linked-list for non-trivially destructible types
    struct DtorNode {
        void (*dtor)(void*);
        DtorNode* prev;
        void* obj;
    };

    char* buf_;
    std::size_t capacity_;
    std::size_t offset_ = 0;
    DtorNode* tail_ = nullptr;

    void call_dtors() {
        while (tail_) {
            tail_->dtor(tail_->obj);
            tail_=tail_->prev;
        }
    }

    // allocate mem of sz bytes with specified alignment
    std::pair<void*, std::size_t> alloc(std::size_t cur_offset, std::size_t sz, std::size_t align) {
        std::size_t space = capacity_ - cur_offset;
        void* align_ptr = buf_ + cur_offset;

        if (std::align(align, sz, align_ptr, space) == nullptr) {
            throw std::bad_alloc();
        }

        std::size_t new_offset = static_cast<char*>(align_ptr) - buf_ + sz;

        return {align_ptr, new_offset};
    }
};

}