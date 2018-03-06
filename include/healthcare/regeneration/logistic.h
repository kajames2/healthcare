#ifndef _HEALTHCARE_REGENERATION_LOGISTIC_H_
#define _HEALTHCARE_REGENERATION_LOGISTIC_H_

#include "healthcare/regeneration.h"

namespace healthcare {
namespace regeneration {

class Logistic : public Regeneration {
 public:
  Logistic(double gamma, double delta, double r);
  int GetHealthRegained(int health, int health_investment) const override;
  int GetRegainCost(int health, int health_regained) const override;

 private:
  double gamma_;
  double delta_;
  double r_;
};

}  // namespace regeneration
}  // namespace healthcare
#endif  // _HEALTHCARE_REGENERATION_LOGISTIC_H_
