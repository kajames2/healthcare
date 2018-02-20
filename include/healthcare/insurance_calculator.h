#ifndef _HEALTHCARE_INSURANCE_CALCULATOR_H_
#define _HEALTHCARE_INSURANCE_CALCULATOR_H_

#include <memory>

#include "healthcare/probability_strategy.h"

namespace healthcaredp {

template <typename T>
class InsuranceCalculator {
 public:
  virtual double GetInsuranceCost(const T &state, const Shock &shock) const {
    return GetShockRecoveryCost(state) * prob_->GetProbability(state);
  }
  virtual double GetShockRecoveryCost(const T &state) const { return 0; }

 private:
  std::shared_ptr<genericdp::ProbabilityStrategy<T>> prob_;
};

}  // namespace healthcaredp

#endif  //_HEALTHCARE_INSURANCE_CALCULATOR_H_
