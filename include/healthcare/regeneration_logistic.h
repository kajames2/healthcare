#ifndef _REGENERATION_LOGISTIC_H_
#define _REGENERATION_LOGISTIC_H_

#include "regeneration_cached.h"
#include <vector>

namespace healthcare {

class RegenerationLogistic : public RegenerationCached {
public:
  RegenerationLogistic(double gamma, double delta, double r);
  RegenerationLogistic(double gamma, double delta, double r,
                       int max_investment);

protected:
  int CalculateHealthRegained(int health, int health_investment) const override;
  int CalculateRegainCost(int health, int health_regained) const override;

private:
  double gamma_;
  double delta_;
  double r_;
};

} // namespace healthcare
#endif // _REGENERATION_LOGISTIC_H_
