#ifndef _CONSUMPTION_LOG_LOGISTIC_H_
#define _CONSUMPTION_LOG_LOGISTIC_H_

#include "consumption_cached.h"
#include <array>
#include <vector>

namespace healthcare {

class ConsumptionLogLogistic : public ConsumptionCached {
public:
  ConsumptionLogLogistic(double alpha, double beta, double c);
  ConsumptionLogLogistic(double alpha, double beta, double c,
                         int max_investment);

private:
  double CalculateLifeEnjoyment(int health, int life_investment) const override;
  double alpha_, beta_, c_;
};

} // namespace healthcare
#endif // _CONSUMPTION_LOG_LOGISTIC_H_
