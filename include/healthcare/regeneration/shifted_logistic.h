#ifndef _HEALTHCARE_REGENERATION_SHIFTED_LOGISTIC_H_
#define _HEALTHCARE_REGENERATION_SHIFTED_LOGISTIC_H_

#include "healthcare/regeneration.h"

namespace healthcare {
namespace regeneration {

class ShiftedLogistic : public Regeneration {
 public:
  explicit ShiftedLogistic(double k);
  int GetHealthRegained(int health, int health_investment) const override;
  int GetRegainCost(int health, int health_regained) const override;

 private:
  double k_;
};

}  // namespace regeneration
}  // namespace healthcare
#endif  // _HEALTHCARE_REGENERATION_SHIFTED_LOGISTIC_H_
