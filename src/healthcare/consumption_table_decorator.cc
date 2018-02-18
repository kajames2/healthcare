#include "consumption_table_decorator.h"

namespace healthcare {

ConsumptionTableDecorator::ConsumptionTableDecorator(
    std::unique_ptr<Consumption> consumption)
    : consumption_(std::move(consumption)), cache_(300) {
  FillTable();
}
ConsumptionTableDecorator::ConsumptionTableDecorator(
    std::unique_ptr<Consumption> consumption, int max_investment)
    : consumption_(std::move(consumption)), cache_(max_investment + 1) {
  FillTable();
};

double ConsumptionTableDecorator::GetLifeEnjoyment(int health,
                                int life_investment) const {
  return cache_[life_investment][health];
};

void ConsumptionTableDecorator::FillTable() {
  for (int li = 0; li < cache_.size(); ++li) {
    for (int h = 0; h <= 100; ++h) {
      cache_[li][h] = consumption_->GetLifeEnjoyment(h, li);
    }
  }
}
}
