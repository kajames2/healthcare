#ifndef _REGENERATION_CACHED_H_
#define _REGENERATION_CACHED_H_

#include "regeneration.h"

#include <array>
#include <vector>
#include <iostream>

namespace healthcare {
class RegenerationCached : public Regeneration {
public:
  RegenerationCached() : cache_(300) {}
  RegenerationCached(int max_investment) : cache_(max_investment + 1){};

  virtual int GetHealthRegained(int health, int health_investment) const override {
    return cache_[health_investment][health];
  };

protected:
  void FillCache() {
    for (int hi = 0; hi < cache_.size(); ++hi) {
      for (int h = 0; h <= 100; ++h) {
        cache_[hi][h] = this->CalculateHealthRegained(h, hi);
      }
    }
  }

  
private:
  virtual int CalculateHealthRegained(int health, int health_investment) const = 0;
  std::vector<std::array<int, 101>> cache_;
};

} // namespace healthcare
#endif // _REGENERATION_CACHED_H_
