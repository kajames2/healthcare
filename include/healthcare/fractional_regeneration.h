#ifndef _FRACTIONAL_REGENERATION_H_
#define _FRACTIONAL_REGENERATION_H_

#include "cached_regeneration.h"
#include <array>
#include <vector>

namespace healthcare {

class FractionalRegeneration : public CachedRegeneration {
public:
  FractionalRegeneration(double k);
  FractionalRegeneration(double k, int max_investment);

private:
  int CalculateHealthRegained(int health, int health_investment) const override;
  double k_;

};

} // namespace healthcare
#endif // _FRACTIONAL_REGENERATION_H_
