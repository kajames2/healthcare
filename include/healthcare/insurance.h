#ifndef _HEALTHCARE_INSURANCE_H_
#define _HEALTHCARE_INSURANCE_H_

namespace healthcare {

class Insurance {
 public:
  virtual int GetCost(int age, int fitness, int health) const = 0;
  virtual ~Insurance() {}
};

}  // namespace healthcare

#endif  // _HEALTHCARE_INSURANCE_H_
