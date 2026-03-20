#pragma once

#include <unordered_map>
#include <vector>

namespace tlow::runtime {

class Graph {

public:
    
    Graph() = default; // call implementation (eventually)



    void add_node();
    void add_edge();


private:
    std::unordered_map<int, std::vector<int>> adj_list;


};


}