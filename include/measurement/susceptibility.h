#pragma once
/**
@file
@brief This file contains a function to measure a model's susceptibility
*/

#include <iostream>
#include <utility>

namespace isinggraph {

//! Measures the average susceptibility over a range of beta
/*!
  Measures the susceptibility of an arbitrary model over a specified range of
  beta
  @param model The model object to use for the simulation
  @param beta_low The lower bound for the range of beta values
  @param beta_high The upper bound for the range of beta values
  @param steps The number of values of beta to sample from the range
  @param avg_steps The number of readings to average over for each measurement
  @param therm_steps The number of updates to do between each measurement
  @return A vector of pairs containing the measurements
*/
template <typename T>
std::vector<std::pair<double, double>> measure_susceptibility(
    T& model, double const& beta_low, double const& beta_high, int steps,
    int avg_steps, int therm_steps) noexcept {
  auto beta = beta_low;
  auto const increment = (beta_high - beta_low) / steps;
  std::vector<std::pair<double, double>> results;

  auto thermalise = [&]() {
    for (int i = 0; i < therm_steps; ++i) {
      model.update(beta);
    }
  };

  while (beta < beta_high) {
    double measurement = 0.0;
    for (int i = 0; i < avg_steps; ++i) {
      thermalise();
      measurement += model.susceptibility();
    }
    results.emplace_back(beta, measurement / avg_steps);
    beta += increment;
  }
  return results;
}

}  // namespace isinggraph
