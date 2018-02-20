#ifndef _HEALTHCARE_RECOVERY_HEALTH_COST_H_
#define _HEALTHCARE_RECOVERY_HEALTH_COST_H_

#include <memory>

#include "healthcare/insurance_calculator.h"

namespace healthcaredp {

template <typename T>
class RecoveryHealthCost : public InsuranceCalculator<T> {
 public:
  explicit RecoveryHealthCost(int cost) : cost_(cost) {}
  RecoveryHealthCost(int cost, std::shared_ptr<InsuranceCalculator<T>> calc) {}

 protected:
  int GetShockRecoveryCost(const T &state) const override;

 private:
};

}  // namespace healthcaredp

#endif  // _HEALTHCARE_RECOVERY_HEALTH_COST_H_
