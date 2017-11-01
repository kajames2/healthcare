#ifndef _INCREASING_DECAY_CONSUMPTION_H_
#define _INCREASING_DECAY_CONSUMPTION_H_

#include "cached_consumption.h"

#include <vector>

namespace healthcare {

class IncreasingDecayConsumption : public CachedConsumption {
public:
  IncreasingDecayConsumption(double alpha, double beta, double c);
  IncreasingDecayConsumption(double alpha, double beta, double c,
                             int max_investment);

private:
  double CalculateLifeEnjoyment(int health, int life_investment) const override;
  double alpha_;
  double beta_;
  double c_;
};

} // namespace healthcare
#endif // _INCREASING_DECAY_CONSUMPTION_H_
