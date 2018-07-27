#ifndef _HEALTHCARE_ENJOYMENT_LOGISTIC_H_
#define _HEALTHCARE_ENJOYMENT_LOGISTIC_H_

#include "healthcare/enjoyment.h"

namespace healthcare {
namespace enjoyment {

class Logistic : public Enjoyment {
 public:
  explicit Logistic(double k);
  double GetEnjoyment(int health, int life_investment) const override;

 private:
  double k_;
};

}  // namespace enjoyment
}  // namespace healthcare
#endif  // _HEALTHCARE_ENJOYMENT_LOGISTIC_H_
