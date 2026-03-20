#pragma once

#include <memory_resource>
#include <vector>

#include "Node.h"
#include "Edge.h"
#include "Tensor.h"

namespace tlow::runtime {

class Graph {

public:
    
    explicit Graph(std::pmr::memory_resource* mr);

    ~Graph() = default;

    Graph(const Graph&) = delete;
    Graph& operator=(const Graph&) = delete;

    Graph(Graph&&) = delete;
    Graph& operator=(Graph&&) = delete;

    int add_node(KernelFn fwd, KernelFn bwd = nullptr);
    int add_edge(int src_node_id, int dst_node_id, Tensor* tensor);

    void forward();
    void backward();

    Node* node(int id) const { return nodes_[id]; }
    Edge* edge(int id) const { return edges_[id]; }
    int num_nodes() const { return nodes_.size(); }
    int num_edges() const { return edges_.size(); }

private:

    std::pmr::memory_resource* mr_;

    std::pmr::vector<Node*> nodes_;
    std::pmr::vector<Edge*> edges_;

    std::pmr::vector<int> topo_ord_;
    std::pmr::vector<int> topo_ord_rev_;
    std::pmr::vector<std::pmr::vector<int>> adj_list_;

    void build_topo(int node_id, std::pmr::vector<bool>& visited);
};


}