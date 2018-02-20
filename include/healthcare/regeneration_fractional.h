#ifndef _HEALTHCARE_REGENERATION_FRACTIONAL_H_
#define _HEALTHCARE_REGENERATION_FRACTIONAL_H_

#include "healthcare/regeneration.h"

namespace healthcare {

class RegenerationFractional : public Regeneration {
 public:
  explicit RegenerationFractional(double k);
  int GetHealthRegained(int health, int health_investment) const override;
  int GetRegainCost(int health, int health_regained) const override;

 private:
  double k_;
};

}  // namespace healthcare
#endif  // _HEALTHCARE_REGENERATION_FRACTIONAL_H_
