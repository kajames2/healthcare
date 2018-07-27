#ifndef _HEALTHCARE_ENJOYMENT_LOG_LOGISTIC_H_
#define _HEALTHCARE_ENJOYMENT_LOG_LOGISTIC_H_

#include "healthcare/enjoyment.h"

namespace healthcare {
namespace enjoyment {

class LogLogistic : public Enjoyment {
 public:
  LogLogistic(double alpha, double beta, double c);
  double GetEnjoyment(int health, int life_investment) const override;

 private:
  double alpha_, beta_, c_;
};

}  // namespace enjoyment
}  // namespace healthcare
#endif  // _HEALTHCARE_ENJOYMENT_LOG_LOGISTIC_H_
