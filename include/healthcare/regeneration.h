#ifndef _HEALTHCARE_REGENERATION_H_
#define _HEALTHCARE_REGENERATION_H_

#include <algorithm>

namespace healthcare {

class Regeneration {
 public:
  virtual ~Regeneration() {}

  virtual int GetHealthRegained(int health, int health_investment) const = 0;
  virtual int GetRegainCost(int health, int health_regained) const = 0;
};

}  // namespace healthcare
#endif  // _HEALTHCARE_REGENERATION_H_
