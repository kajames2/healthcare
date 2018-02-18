#ifndef _REGENERATION_FRACTIONAL_H_
#define _REGENERATION_FRACTIONAL_H_

#include "regeneration.h"

namespace healthcare {

class RegenerationFractional : public Regeneration {
public:
  RegenerationFractional(double k);
  int GetHealthRegained(int health, int health_investment) const override;
  int GetRegainCost(int health, int health_regained) const override;

private:
  double k_;
};

} // namespace healthcare
#endif // _REGENERATION_FRACTIONAL_H_
