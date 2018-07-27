#ifndef _HEALTHCARE_PROBABILITY_H_
#define _HEALTHCARE_PROBABILITY_H_

namespace healthcare {

class Probability {
 public:
  virtual float operator()(int age) const = 0;
  virtual ~Probability() {}
};

}  // namespace healthcare

#endif  // _HEALTHCARE_PROBABILITY_H_
