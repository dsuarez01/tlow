#pragma once

#include <cstddef>
#include <cstdint>
#include <array>
#include <memory_resource>

namespace tlow::runtime {

enum class DType {
    Float32,
    Float16,
    BFloat16,
    Int8,
    Int32,
    Int64,
};

enum class Layout {
    RowMajor,
    ColMajor,
};

class Tensor {

public:

    static constexpr std::size_t kMaxRank = 4;

    Tensor(
        std::pmr::memory_resource* mr,
        std::array<int64_t, kMaxRank> shape,
        std::size_t rank,
        DType dtype,
        Layout layout = Layout::RowMajor,
        std::size_t alignment = alignof(std::max_align_t)
    );

    ~Tensor() = default;

    Tensor(const Tensor&) = delete;
    Tensor& operator=(const Tensor&) = delete;

    Tensor(Tensor&&) = delete;
    Tensor& operator=(Tensor&&) = delete;

    std::size_t rank() const { return rank_; }
    const std::array<int64_t, kMaxRank>& shape() const { return shape_; }
    const std::array<int64_t, kMaxRank>& strides() const { return strides_; }
    DType dtype() const { return dtype_; }
    void* data() const { return data_; }

private:

    void* data_;
    DType dtype_;
    std::size_t rank_;
    std::array<int64_t, kMaxRank> shape_;
    std::array<int64_t, kMaxRank> strides_;

};

int64_t num_elements(const Tensor& t);
std::size_t byte_size(const Tensor& t);
std::size_t dtype_size(DType dtype);

// view: allocate new Tensor descriptor pointing at existing data buf
Tensor* view(
    void* data,
    std::array<int64_t, Tensor::kMaxRank> shape,
    std::array<int64_t, Tensor::kMaxRank> strides,
    std::size_t rank,
    DType dtype,
    std::pmr::memory_resource* mr
);

}