#ifndef _REGENERATION_SHIFTED_LOGISTIC_H_
#define _REGENERATION_SHIFTED_LOGISTIC_H_

#include "regeneration_cached.h"
#include <array>
#include <vector>

namespace healthcare {

class RegenerationShiftedLogistic : public RegenerationCached {
public:
  explicit RegenerationShiftedLogistic(double k);
  RegenerationShiftedLogistic(double k, int max_investment);

protected:
  int CalculateHealthRegained(int health, int health_investment) const override;
  int CalculateRegainCost(int health, int health_regained) const override;

private:
  double k_;
};

} // namespace healthcare
#endif // _REGENERATION_SHIFTED_LOGISTIC_H_
