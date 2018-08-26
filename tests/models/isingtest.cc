#include "models/ising.h"
#include "gtest/gtest.h"

TEST(IsingTest, Instantiation) {
  using namespace isinggraph;

  Ising<ising::Metropolis, Graph> ising_graph({{1, 2}, {0, 2}});
  Ising<ising::Metropolis, Grid2D> ising_grid(10);
}
