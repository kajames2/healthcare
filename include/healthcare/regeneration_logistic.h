#ifndef _REGENERATION_LOGISTIC_H_
#define _REGENERATION_LOGISTIC_H_

#include "regeneration_cached.h"
#include <vector>

namespace healthcare {

class RegenerationLogistic : public RegenerationCached {
public:
  RegenerationLogistic(double gamma, double delta, double r);
  RegenerationLogistic(double gamma, double delta, double r, int max_investment);

private:
  int CalculateHealthRegained(int health, int health_investment) const override;
  double gamma_;
  double delta_;
  double r_;
};

} // namespace healthcare
#endif // _REGENERATION_LOGISTIC_H_
