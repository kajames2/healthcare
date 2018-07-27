#ifndef _HEALTHCARE_FITNESS_H_
#define _HEALTHCARE_FITNESS_H_

namespace healthcare {

class Fitness {
 public:
  virtual int GetFitness(int investment) const =0;
  virtual int GetCost(int fitness) const = 0;
  virtual ~Fitness() {}
};

}  // namespace healthcare
#endif  // _HEALTHCARE_FITNESS_H_
