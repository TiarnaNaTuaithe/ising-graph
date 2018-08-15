#pragma once
/**
@file
@brief This file contains a simple arbitrary graph implementation
 */

#include <vector>

namespace isinggraph {
namespace graph {

//! An unweighted, undirected, arbitrarily connected graph
class Graph {
 public:
  //! A constuctor from a neighbour vector
  Graph(std::vector<std::vector<int>> n) : neighbours_{n} {
  }

  //! Get the neighbours of a given node
  std::vector<int> const& neighbours(int node) {
    return neighbours_[node];
  }

  //! Get the degree of a given node
  int degree(int n) {
    return neighbours_[n].size();
  }

  //! Get the number of nodes in the graph
  int size() {
    return neighbours_.size();
  }

 private:
  std::vector<std::vector<int>> neighbours_;
};

}  // namespace graph
}  // namespace isinggraph
