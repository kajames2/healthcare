#ifndef _CONSUMPTION_TABLE_DECORATOR_H_
#define _CONSUMPTION_TABLE_DECORATOR_H_

#include "consumption.h"

#include <array>
#include <vector>
#include <memory>

namespace healthcare {
class ConsumptionTableDecorator : public Consumption {
public:
  explicit ConsumptionTableDecorator(std::unique_ptr<Consumption> consumption);
  ConsumptionTableDecorator(std::unique_ptr<Consumption> consumption,
                            int max_investment);
  virtual double GetLifeEnjoyment(int health,
                                  int life_investment) const override;

private:
  void FillTable();
  std::vector<std::array<double, 101>> cache_;
  std::unique_ptr<Consumption> consumption_;
};

} // namespace healthcare
#endif // _CONSUMPTION_TABLE_DECORATOR_H_
