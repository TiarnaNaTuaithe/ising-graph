#include "graph/graph.h"
#include "gtest/gtest.h"

TEST(GraphTest, GraphConstruction) {
  using namespace isinggraph::graph;
  Graph<weight::None> g({{3, 1}, {0, 2}, {1, 3}, {2, 0}});

  for (int i = 0; i < g.size(); ++i) {
    auto x = std::vector<int>{(4 + i - 1) % 4, (i + 1) % 4};
    EXPECT_EQ(x, g.neighbours(i));
    EXPECT_EQ(2, g.degree(i));

    for (int j = 0; j < g.degree(i); ++j) {
      EXPECT_EQ(1, g.weight(i, j));
    }
  }
}
