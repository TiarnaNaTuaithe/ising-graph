#pragma once
/**
@file
@brief This file contains a 2D grid implementation which doesn't require
neighbour storage
 */

#include <array>

namespace isinggraph {

//! A two dimensional square grid with toroidal boundaries, which doesn't store
//! neighbours
class Grid2D {
 public:
  //! A constuctor from a side length
  Grid2D(int n) : side_length_{n} {
  }

  //! Get the neighbours of a given node
  auto const& neighbours(int node) const noexcept {
    neighbours_[0] =
        (node + 1) % side_length_ + side_length_ * (node / side_length_);
    neighbours_[1] = (node + side_length_) % this->size();
    neighbours_[2] = (side_length_ + node - 1) % side_length_ +
                     side_length_ * (node / side_length_);
    neighbours_[3] = (this->size() + node - side_length_) % this->size();
    return neighbours_;
  }

  //! Get the degree of a given node
  constexpr int degree(int) const noexcept {
    return 4;
  }

  //! Get the number of nodes in the graph
  constexpr int size() const noexcept {
    return side_length_ * side_length_;
  }

 private:
  int side_length_;
  mutable std::array<int, 4> neighbours_ = {0, 0, 0, 0};
};

}  // namespace isinggraph
