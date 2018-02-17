#ifndef _CONSUMPTION_CACHED_H_
#define _CONSUMPTION_CACHED_H_

#include "consumption.h"

#include <array>
#include <vector>

namespace healthcare {
class ConsumptionCached : public Consumption {
public:
  ConsumptionCached() : cache_(300) {}
  ConsumptionCached(int max_investment) : cache_(max_investment + 1){};

  virtual double GetLifeEnjoyment(int health,
                                  int life_investment) const override {
    return cache_[life_investment][health];
  };

protected:
  void FillCache() {
    for (int li = 0; li < cache_.size(); ++li) {
      for (int h = 0; h <= 100; ++h) {
        cache_[li][h] = this->CalculateLifeEnjoyment(h, li);
      }
    }
  }
  virtual double CalculateLifeEnjoyment(int health,
                                        int life_investment) const = 0;

private:
  std::vector<std::array<double, 101>> cache_;
};

} // namespace healthcare
#endif // _CONSUMPTION_CACHED_H_
