#ifndef _HEALTHCARE_REGENERATION_SHIFTED_LOGISTIC_H_
#define _HEALTHCARE_REGENERATION_SHIFTED_LOGISTIC_H_

#include "regeneration.h"
namespace healthcare {

class RegenerationShiftedLogistic : public Regeneration {
 public:
  explicit RegenerationShiftedLogistic(double k);
  int GetHealthRegained(int health, int health_investment) const override;
  int GetRegainCost(int health, int health_regained) const override;

 private:
  double k_;
};

}  // namespace healthcare
#endif  // _HEALTHCARE_REGENERATION_SHIFTED_LOGISTIC_H_
