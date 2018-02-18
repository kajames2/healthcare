#ifndef _CONSUMPTION_INCREASING_DECAY_H_
#define _CONSUMPTION_INCREASING_DECAY_H_

#include "consumption.h"

namespace healthcare {

class ConsumptionIncreasingDecay : public Consumption {
public:
  ConsumptionIncreasingDecay(double alpha, double beta, double c);
  double GetLifeEnjoyment(int health, int life_investment) const override;

private:
  double alpha_;
  double beta_;
  double c_;
};

} // namespace healthcare
#endif // _CONSUMPTION_INCREASING_DECAY_H_
