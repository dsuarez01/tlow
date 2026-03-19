#pragma once

#include <cstddef>
#include <memory>
#include <new>

namespace tlow::runtime {

class Arena {
public:

    Arena() = delete;

    explicit Arena(std::size_t sz) 
        : buf_(static_cast<char*>(::operator new(sz))), 
          capacity_(sz), 
          offset_(0) {}

    Arena(const Arena&) = delete;
    Arena& operator=(const Arena&) = delete;

    Arena(Arena&&) = delete;
    Arena& operator=(Arena&&) = delete;

    ~Arena() {
        ::operator delete(buf_);
    }

    // alloc mem of sz bytes with specified alignment
    void* allocate(std::size_t sz, std::size_t align) {
        std::size_t space = capacity_-offset_;
        void* align_ptr = buf_ + offset_;

        if (std::align(align, sz, align_ptr, space) == nullptr) {
            throw std::bad_alloc();
        }

        offset_ = static_cast<char*>(align_ptr) - buf_ + sz;

        return align_ptr;
    }

    void reset() {
        offset_ = 0;
    }

private:
    char* buf_;
    std::size_t offset_;
    std::size_t capacity_;
};


}