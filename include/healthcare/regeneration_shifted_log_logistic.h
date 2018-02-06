#ifndef _REGENERATION_SHIFTED_LOG_LOGISTIC_H_
#define _REGENERATION_SHIFTED_LOG_LOGISTIC_H_

#include "regeneration_cached.h"
#include <array>
#include <vector>

namespace healthcare {

class RegenerationShiftedLogLogistic : public RegenerationCached {
public:
  RegenerationShiftedLogLogistic(double alpha, double beta);
  RegenerationShiftedLogLogistic(double alpha, double beta, int max_investment);

private:
  int CalculateHealthRegained(int health, int health_investment) const override;
  double alpha_, beta_;
};

} // namespace healthcare
#endif // _REGENERATION_SHIFTED_LOG_LOGISTIC_H_
