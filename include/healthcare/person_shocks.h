#ifndef _HEALTHCARE_PERSON_SHOCKS_H_
#define _HEALTHCARE_PERSON_SHOCKS_H_

#include "healthcare/degeneration.h"
#include "healthcare/person.h"

namespace healthcare {
class PersonShocks : public Person {
 public:
  PersonShocks();
  PersonShocks(int a, int h, int c);
  bool IsShocked() const { return shock_ != 0; }
  bool IsInsured() const { return insured_; }
  void Insure(int cost);
  void Shock(int shock_size);
  void ReceiveInsuranceSettlement(int cash_payment, int health_payment);

 private:
  int shock_;
  bool insured_;
};

}  // namespace healthcare
#endif  // _HEALTHCARE_PERSON_SHOCKS_H_
