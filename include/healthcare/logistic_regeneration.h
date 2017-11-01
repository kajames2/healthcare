#ifndef _LOGISTIC_REGENERATION_H_
#define _LOGISTIC_REGENERATION_H_

#include "cached_regeneration.h"
#include <vector>

namespace healthcare {

class LogisticRegeneration : public CachedRegeneration {
public:
  LogisticRegeneration(double gamma, double delta, double r);
  LogisticRegeneration(double gamma, double delta, double r, int max_investment);

private:
  int CalculateHealthRegained(int health, int health_investment) const override;
  double gamma_;
  double delta_;
  double r_;
};

} // namespace healthcare
#endif // _LOGISTIC_REGENERATION_H_
