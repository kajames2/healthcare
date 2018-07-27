#ifndef _HEALTHCARE_PROBABILITY_FITNESS_MODULATED_H_
#define _HEALTHCARE_PROBABILITY_FITNESS_MODULATED_H_

#include <memory>
#include <vector>

#include "healthcare/probability.h"

namespace healthcaredp {

template <typename T>
class ProbabilityFitnessModulated : public genericdp::Probability<T> {
 public:
  ProbabilityFitnessModulated(
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
