#ifndef _HEALTHCARE_RETIREMENT_INCOME_H_
#define _HEALTHCARE_RETIREMENT_INCOME_H_

namespace healthcare {
class RetirementIncome {
 public:
  RetirementIncome(int n_harvest_periods, double earning_frac);
  int GetIncome(int period, int total_harvest) const;

 private:
  double earning_frac_;
  int n_working_periods_;
};
}  // namespace healthcare
#endif  // _HEALTHCARE_RETIREMENT_INCOME_H_
