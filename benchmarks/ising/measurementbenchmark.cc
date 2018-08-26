#include "benchmark/benchmark.h"
#include "models/ising.h"
#include "measurement/susceptibility.h"

static void BM_SUSCEPTIBILITY(benchmark::State &state) {
  using namespace isinggraph;
  Ising<ising::Metropolis, Grid2D> ising_grid(100);
  for (auto _ : state) {
    measure_susceptibility(ising_grid, 0.1, 1.0, 100, 10, 10);
  }
}

// Register the function as a benchmark
BENCHMARK(BM_SUSCEPTIBILITY);
