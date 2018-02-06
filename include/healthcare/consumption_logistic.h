#ifndef _CONSUMPTION_LOGISTIC_H_
#define _CONSUMPTION_LOGISTIC_H_

#include "consumption_cached.h"

#include <vector>

namespace healthcare {

class ConsumptionLogistic : public ConsumptionCached {
public:
  explicit ConsumptionLogistic(double k);
  ConsumptionLogistic(double k, int max_investment);
  double CalculateLifeEnjoyment(int health, int life_investment) const override;

private:
  double k_;
};

} // namespace healthcare
#endif // _CONSUMPTION_LOGISTIC_H_
