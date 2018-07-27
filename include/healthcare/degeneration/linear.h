#ifndef _HEALTHCARE_DEGENERATION_LINEAR_H_
#define _HEALTHCARE_DEGENERATION_LINEAR_H_

#include "healthcare/degeneration.h"

namespace healthcare {
namespace degeneration {

class Linear : public Degeneration {
 public:
  explicit Linear(float degen_intercept);
  Linear(float degen_intercept, float degen_slope);
  int GetDegeneration(int age, int health) const override;

 private:
  float degen_slope_;
  float degen_intercept_;
};

}  // namespace degeneration
}  // namespace healthcare
#endif  // _HEALTHCARE_DEGENERATION_LINEAR_H_
