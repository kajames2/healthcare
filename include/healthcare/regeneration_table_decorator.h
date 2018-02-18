#ifndef _REGENERATION_TABLE_DECORATOR_H_
#define _REGENERATION_TABLE_DECORATOR_H_

#include "regeneration.h"

#include <array>
#include <memory>
#include <vector>

namespace healthcare {
class RegenerationTableDecorator : public Regeneration {
public:
  explicit RegenerationTableDecorator(std::unique_ptr<Regeneration> regen);
  RegenerationTableDecorator(std::unique_ptr<Regeneration> regen,
                             int max_investment);
  virtual int GetHealthRegained(int health,
                                int health_investment) const override;

  virtual int GetRegainCost(int health, int health_regained) const override;

private:
  void FillTables();
  std::vector<std::array<int, 101>> cache_;
  std::array<std::array<int, 101>, 101> cache2_;
  std::unique_ptr<Regeneration> regen_;
};

} // namespace healthcare
#endif // _REGENERATION_TABLE_DECORATOR_H_
