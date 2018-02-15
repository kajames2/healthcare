#ifndef _REGENERATION_CACHED_H_
#define _REGENERATION_CACHED_H_

#include "regeneration.h"

#include <array>
#include <iostream>
#include <vector>

namespace healthcare {
class RegenerationCached : public Regeneration {
public:
  RegenerationCached() : cache_(300) {}
  RegenerationCached(int max_investment) : cache_(max_investment + 1){};

  virtual int GetHealthRegained(int health,
                                int health_investment) const override {
    return cache_[health_investment][health];
  };

  virtual int GetRegainCost(int health, int health_regained) const override {
    return cache_[health_regained][health];
  };

protected:
  void FillCache() {
    for (int hi = 0; hi < cache_.size(); ++hi) {
      for (int h = 0; h <= 100; ++h) {
        cache_[hi][h] = this->CalculateHealthRegained(h, hi);
      }
    }
    for (int h = 0; h <= 100; ++h) {
      for (int hr = 0; hr < 100 - h; ++hr) {
        cache2_[hr][h] = this->CalculateRegainCost(h, hr);
      }
    }
  }

protected:
  virtual int CalculateHealthRegained(int health,
                                      int health_investment) const = 0;
  virtual int CalculateRegainCost(int health, int health_investment) const = 0;

private:
  std::vector<std::array<int, 101>> cache_;
  std::array<std::array<int, 101>, 101> cache2_;
};

} // namespace healthcare
#endif // _REGENERATION_CACHED_H_
