#ifndef _HEALTHCARE_ENJOYMENT_H_
#define _HEALTHCARE_ENJOYMENT_H_

namespace healthcare {

class Enjoyment {
 public:
  virtual double GetEnjoyment(int health, int life_investment) const = 0;
  virtual ~Enjoyment() {}
};

}  // namespace healthcare
#endif  // _HEALTHCARE_ENJOYMENT_H_
