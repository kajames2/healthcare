#ifndef _HEALTHCARE_REGENERATION_LOGISTIC_H_
#define _HEALTHCARE_REGENERATION_LOGISTIC_H_

#include "healthcare/regeneration.h"

namespace healthcare {

class RegenerationLogistic : public Regeneration {
 public:
  RegenerationLogistic(double gamma, double delta, double r);
  int GetHealthRegained(int health, int health_investment) const override;
  int GetRegainCost(int health, int health_regained) const override;

 private:
  double gamma_;
  double delta_;
  double r_;
};

}  // namespace healthcare
#endif  // _HEALTHCARE_REGENERATION_LOGISTIC_H_
