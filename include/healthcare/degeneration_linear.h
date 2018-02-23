#ifndef _HEALTHCARE_DEGENERATION_LINEAR_H_
#define _HEALTHCARE_DEGENERATION_LINEAR_H_

#include "healthcare/degeneration.h"

namespace healthcare {
class DegenerationLinear : public Degeneration {
 public:
  explicit DegenerationLinear(double degen_intercept);
  DegenerationLinear(double degen_intercept, double degen_slope);
  int GetDegeneration(int age, int health) const override;

 private:
  double degen_slope_;
  double degen_intercept_;
};

}  // namespace healthcare
#endif  // _HEALTHCARE_DEGENERATION_LINEAR_H_
