#ifndef _HEALTHCARE_PROBABILITY_PERIOD_DEFINED_H_
#define _HEALTHCARE_PROBABILITY_PERIOD_DEFINED_H_

#include <vector>

#include "healthcare/probability_strategy.h"

namespace healthcaredp {

template <typename T>
class ProbabilityPeriodDefined : public genericdp::ProbabilityStrategy<T> {
 public:
  ProbabilityPeriodDefined(std::vector<double> probs) : probs_(probs) {}
  double GetProbability(const T &state) const override {
    return probs_[state.period];
  }

 private:
  std::vector<double> probs_;
};

}  // namespace healthcaredp

#endif  //_HEALTHCARE_PROBABILITY_PERIOD_DEFINED_H_
