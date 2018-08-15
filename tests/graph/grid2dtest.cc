#include "graph/grid2d.h"
#include "gtest/gtest.h"

TEST(Grid2DTest, Grid2DConstruction) {
  isinggraph::Grid2D g(3);

  std::vector<int> zero_neighbours{1, 3, 2, 6};
  EXPECT_EQ(zero_neighbours, g.neighbours(0));

  std::vector<int> one_neighbours{2, 4, 0, 7};
  EXPECT_EQ(one_neighbours, g.neighbours(1));

  std::vector<int> two_neighbours{0, 4, 1, 8};
  EXPECT_EQ(one_neighbours, g.neighbours(1));

  std::vector<int> three_neighbours{4, 6, 5, 0};
  EXPECT_EQ(one_neighbours, g.neighbours(1));

  std::vector<int> four_neighbours{5, 7, 3, 1};
  EXPECT_EQ(four_neighbours, g.neighbours(4));

  std::vector<int> five_neighbours{3, 8, 4, 2};
  EXPECT_EQ(one_neighbours, g.neighbours(1));

  std::vector<int> six_neighbours{7, 0, 8, 3};
  EXPECT_EQ(one_neighbours, g.neighbours(1));

  std::vector<int> seven_neighbours{8, 1, 6, 4};
  EXPECT_EQ(seven_neighbours, g.neighbours(7));

  std::vector<int> eight_neighbours{6, 2, 7, 5};
  EXPECT_EQ(eight_neighbours, g.neighbours(8));
}

TEST(Grid2DTest, Grid2DEdges) {
  isinggraph::Grid2D g(4);
  std::vector<int> counter(g.size(), 0);

  for (int i = 0; i < g.size(); ++i) {
    for (auto const n : g.neighbours(i)) {
      counter[n]++;
    }
  }

  // Each node should be mentioned exactly four times.
  for (auto const value : counter) {
    EXPECT_EQ(4, value);
  }
}
