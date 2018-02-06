#ifndef _INSURANCE_CALCULATOR_H_
#define _INSURANCE_CALCULATOR_H_

#include "probability_strategy.h"
#include <memory>

namespace healthcaredp {

template <typename T> class InsuranceCalculator {
public:
  virtual double GetInsuranceCost(const T &state) const {
    return GetShockRecoveryCost(state) * prob_->GetProbability(state);
  }
  virtual double GetShockRecoveryCost(const T &state) const { return 0; }
private:
  std::shared_ptr<genericdp::ProbabilityStrategy<T>> prob_;
};

} // namespace genericdp

#endif //_INSURANCE_CALCULATOR_H_
