#ifndef _HEALTHCARE_PERSON_RETIRES_H_
#define _HEALTHCARE_PERSON_RETIRES_H_

#include "healthcare/person.h"
#include "healthcare/job.h"
#include "healthcare/retirement_income.h"

namespace healthcare {
class PersonRetires : public Person {
 public:
  PersonRetires();
  PersonRetires(int a, int h, int c, int le);
  void Work(const Job* job);
  void CollectRetirement(const RetirementIncome* retirement);
  int GetLifetimeEarnings() const { return lifetime_earnings_; }

 private:
  int lifetime_earnings_;
};

}  // namespace healthcare
#endif  // _HEALTHCARE_PERSON_RETIRES_H_
