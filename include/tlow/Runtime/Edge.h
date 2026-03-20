#pragma once

#include "Tensor.h"

namespace tlow::runtime {

class Edge {
public:
    Edge(int id, Tensor* tensor);

    int id() const { return id_; }
    Tensor* tensor() const { return tensor_; }
    Tensor* grad() const { return grad_; }

    void set_grad(Tensor* grad) { grad_ = grad; }

private:
    int id_;
    Tensor* tensor_;
    Tensor* grad_ = nullptr; // null during inference, set during backward
};


}