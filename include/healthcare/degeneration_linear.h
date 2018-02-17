#ifndef _DEGENERATION_LINEAR_H_
#define _DEGENERATION_LINEAR_H_

#include "degeneration.h"

namespace healthcare {
class DegenerationLinear : public Degeneration {
public:
  explicit DegenerationLinear(double degen_intercept);
  DegenerationLinear(double degen_intercept, double degen_slope);
  int GetDegeneration(int period) const override;

private:
  double degen_slope_;
  double degen_intercept_;
};

} // namespace healthcare
#endif // _DEGENERATION_LINEAR_H_
