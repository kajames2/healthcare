#ifndef _REGENERATION_SHIFTED_LOG_LOGISTIC_H_
#define _REGENERATION_SHIFTED_LOG_LOGISTIC_H_

#include "regeneration.h"

namespace healthcare {

class RegenerationShiftedLogLogistic : public Regeneration {
public:
  RegenerationShiftedLogLogistic(double alpha, double beta);
  int GetHealthRegained(int health, int health_investment) const override;
  int GetRegainCost(int health, int health_regained) const override;

private:
  double alpha_, beta_;
};

} // namespace healthcare
#endif // _REGENERATION_SHIFTED_LOG_LOGISTIC_H_
