#ifndef _CONSUMPTION_INCREASING_DECAY_H_
#define _CONSUMPTION_INCREASING_DECAY_H_

#include "consumption_cached.h"

#include <vector>

namespace healthcare {

class ConsumptionIncreasingDecay : public ConsumptionCached {
public:
  ConsumptionIncreasingDecay(double alpha, double beta, double c);
  ConsumptionIncreasingDecay(double alpha, double beta, double c,
                             int max_investment);

private:
  double CalculateLifeEnjoyment(int health, int life_investment) const override;
  double alpha_;
  double beta_;
  double c_;
};

} // namespace healthcare
#endif // _CONSUMPTION_INCREASING_DECAY_H_
