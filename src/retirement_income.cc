#include "healthcare/retirement_income.h"

#include <cmath>

namespace healthcare {
RetirementIncome::RetirementIncome(int n_working_periods, double earning_frac)
    : n_working_periods_(n_working_periods), earning_frac_(earning_frac) {}

int RetirementIncome::GetIncome(int period, int total_job) const {
  if (period <= n_working_periods_) {
    return 0;
  }
  return std::round(total_job * earning_frac_ / n_working_periods_);
}
}  // namespace healthcare
