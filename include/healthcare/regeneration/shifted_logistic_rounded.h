#ifndef _HEALTHCARE_REGENERATION_SHIFTED_LOGISTIC_ROUNDED_H_
#define _HEALTHCARE_REGENERATION_SHIFTED_LOGISTIC_ROUNDED_H_

#include <vector>

#include "healthcare/regeneration.h"

namespace healthcare {
namespace regeneration {

class ShiftedLogisticRounded : public Regeneration {
 public:
  explicit ShiftedLogisticRounded(double k);
  int GetHealthRegained(int health, int health_investment) const override;
  int GetRegainCost(int health, int health_regained) const override;

 private:
  double k_;
  std::vector<int> cost_vec_;
  int CalculateRegainCost(int health, int health_regained) const;
};

}  // namespace regeneration
}  // namespace healthcare
#endif  // _HEALTHCARE_REGENERATION_SHIFTED_LOGISTIC_ROUNDED_H_
