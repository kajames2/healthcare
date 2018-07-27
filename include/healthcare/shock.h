#ifndef _HEALTHCARE_SHOCK_H_
#define _HEALTHCARE_SHOCK_H_

namespace healthcare {

class Shock {
 public:
  virtual int operator()(int fitness) const = 0;
  virtual ~Shock() {}
};

}  // namespace healthcare

#endif  // _HEALTHCARE_SHOCK_H_
