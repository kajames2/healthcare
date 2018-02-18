#include "regeneration_table_decorator.h"

#include <memory>

namespace healthcare {

RegenerationTableDecorator::RegenerationTableDecorator(
    std::unique_ptr<Regeneration> regen)
    : regen_(std::move(regen)), cache_(300) {
  FillTables();
}

RegenerationTableDecorator::RegenerationTableDecorator(
    std::unique_ptr<Regeneration> regen, int max_investment)
    : regen_(std::move(regen)), cache_(max_investment + 1) {
  FillTables();
};

int RegenerationTableDecorator::GetHealthRegained(int health,
                                                  int health_investment) const {
  return cache_[health_investment][health];
};

int RegenerationTableDecorator::GetRegainCost(int health,
                                              int health_regained) const {
  return cache2_[health_regained][health];
};

void RegenerationTableDecorator::FillTables() {
  for (int hi = 0; hi < cache_.size(); ++hi) {
    for (int h = 0; h <= 100; ++h) {
      cache_[hi][h] = regen_->GetHealthRegained(h, hi);
    }
  }

  for (int hr = 0; hr <= 100; ++hr) {
    for (int h = 0; h <= 100; ++h) {
      cache2_[hr][h] = regen_->GetRegainCost(h, hr);
    }
  }
}
}
