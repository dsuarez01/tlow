
#pragma once

#include <vector>

#include "Tensor.h"

namespace tlow::runtime {

using KernelFn = void(*)(const std::vector<Tensor*>& inputs, std::vector<Tensor*>& outputs);

class Node {
public:
    Node(int id, KernelFn fwd, KernelFn bwd = nullptr);

    int id() const { return id_; }
    KernelFn forward() const { return fwd_; }
    KernelFn backward() const { return bwd_; }

private:
    int id_;
    KernelFn fwd_;
    KernelFn bwd_; // not all ops differentiable, so this is nullable
};

}