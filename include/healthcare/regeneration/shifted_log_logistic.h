#ifndef _HEALTHCARE_REGENERATION_SHIFTED_LOG_LOGISTIC_H_
#define _HEALTHCARE_REGENERATION_SHIFTED_LOG_LOGISTIC_H_

#include "healthcare/regeneration.h"

namespace healthcare {
namespace regeneration {

class ShiftedLogLogistic : public Regeneration {
 public:
  ShiftedLogLogistic(double alpha, double beta);
  int GetHealthRegained(int health, int health_investment) const override;
  int GetRegainCost(int health, int health_regained) const override;

 private:
  double alpha_, beta_;
};

}  // namespace regeneration
}  // namespace healthcare
#endif  // _HEALTHCARE_REGENERATION_SHIFTED_LOG_LOGISTIC_H_
