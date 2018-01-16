#ifndef _REGENERATION_H_
#define _REGENERATION_H_

#include <algorithm>

namespace healthcare {
class Regeneration {
 public:
  Regeneration() = default;
  Regeneration(const Regeneration&) = delete;
  Regeneration& operator=(const Regeneration&) = delete;
  virtual ~Regeneration() {}

  virtual int GetHealthRegained(int health, int health_investment) const = 0;
};
}  // namespace healthcare
#endif  // _REGENERATION_H_
