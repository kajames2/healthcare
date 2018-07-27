#ifndef _HEALTHCARE_ENJOYMENT_FRACTIONAL_H_
#define _HEALTHCARE_ENJOYMENT_FRACTIONAL_H_

#include "healthcare/enjoyment.h"

namespace healthcare {
namespace enjoyment {

class Fractional : public Enjoyment {
 public:
  explicit Fractional(double j);
  double GetEnjoyment(int health, int life_investment) const override;

 private:
  double j_;
};

}  // namespace enjoyment
}  // namespace healthcare
#endif  // _HEALTHCARE_ENJOYMENT_FRACTIONAL_H_
