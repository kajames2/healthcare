#ifndef _CONSUMPTION_H_
#define _CONSUMPTION_H_

namespace healthcare {

class Consumption {
 public:
  virtual double GetLifeEnjoyment(int health, int life_investment) const = 0;
  virtual ~Consumption() {}
};

}  // namespace healthcare
#endif  // _CONSUMPTION_H_
