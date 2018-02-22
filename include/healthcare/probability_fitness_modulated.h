#ifndef _HEALTHCARE_FITNESS_MODULATED_PROBABILITY_H_
#define _HEALTHCARE_FITNESS_MODULATED_PROBABILITY_H_

#include <memory>
#include <vector>

#include "healthcare/health_state_fitness.h"
#include "healthcare/probability_strategy.h"

namespace healthcaredp {

template <typename T>
class FitnessModulatedProbability : public genericdp::ProbabilityStrategy<T> {
 public:
  FitnessModulatedProbability(
      std::shared_ptr<genericdp::ProbabilityStrategy<T>> prob,
      std::vector<double> mods)
      : prob_(prob), mods_(mods) {}
  double GetProbability(const T &state) const override {
    return mods_[state.fitness] * prob_.GetProbability(state);
  }

 private:
  std::shared_ptr<genericdp::ProbabilityStrategy<T>> prob_;
  std::vector<double> mods_;
};

}  // namespace healthcaredp

#endif  // _HEALTHCARE_FITNESS_MODULATED_PROBABILITY_H_
