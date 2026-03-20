#pragma once

#include <cstddef>
#include <memory_resource>
#include "Arena.h"

namespace tlow::runtime {

// subclass pmr::memory_resource (actually handles alignment)
// rather than implementing allocator interface

// NOTE: allocation should be off of the critical path (vtable dispatch)
class ArenaResource : public std::pmr::memory_resource {

public:
    ArenaResource() = delete;
    explicit ArenaResource(Arena* arena) : arena_(arena) {}

    ArenaResource(const ArenaResource&) = default;
    ArenaResource& operator=(const ArenaResource&) = default;

    ArenaResource(ArenaResource&&) = default;
    ArenaResource& operator=(ArenaResource&&) = default;

    ~ArenaResource() = default;

private:
    Arena* arena_;

    void* do_allocate(std::size_t sz, std::size_t align) override {
        return arena_->alloc_raw(sz, align);
    }

    // no-op (arena manages resource lifetimes)
    void do_deallocate(void*, std::size_t, std::size_t) noexcept override {}

    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override {
        return this == &other;
    }
};

}