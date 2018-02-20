#ifndef _HEALTHCARE_RECOVERY_FIXED_COST_H_
#define _HEALTHCARE_RECOVERY_FIXED_COST_H_

#include <memory>

#include "healthcare/insurance_calculator.h"

namespace healthcaredp {

template <typename T>
class RecoveryFixedCost : public InsuranceCalculator<T> {
 public:
  explicit RecoveryFixedCost(int cost) : cost_(cost) {}
  RecoveryFixedCost(int cost, std::shared_ptr<InsuranceCalculator<T>> calc)
      : cost_(cost), calc_(calc) {}

 protected:
  int GetShockRecoveryCost(const T &state) const override {
    return cost_ + calc_->GetShockRecoveryCost();
  }

 private:
  std::shared_ptr<InsuranceCalculator<T>> calc_;
  int cost_;
};

}  // namespace healthcaredp

#endif  // _HEALTHCARE_RECOVERY_FIXED_COST_H_
