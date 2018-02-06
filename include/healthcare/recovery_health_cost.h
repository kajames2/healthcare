#ifndef _RECOVERY_HEALTH_COST_H_
#define _RECOVERY_HEALTH_COST_H_

#include "insurance_calculator.h"
#include <memory>

namespace healthcaredp {

template <typename T> class RecoveryHealthCost : public InsuranceCalculator<T> {
public:
  explicit RecoveryHealthCost(int cost) : cost_(cost) {}
  RecoveryHealthCost(int cost, std::shared_ptr<InsuranceCalculator<T>> calc) {}

protected:
  int GetShockRecoveryCost(const T &state) const override;

private:
};

} // namespace genericdp

#endif // _RECOVERY_HEALTH_COST_H_
