#ifndef _HEALTHCARE_HARVEST_H_
#define _HEALTHCARE_HARVEST_H_

namespace healthcare {
class Harvest {
 public:
  virtual int GetHarvest(int age, int health) const = 0;
  virtual ~Harvest() {}
};
}  // namespace healthcare
#endif  // _HEALTHCARE_HARVEST_H_
