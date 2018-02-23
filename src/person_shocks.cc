#include "healthcare/person_shocks.h"

#include "healthcare/person.h"

namespace healthcare {

PersonShocks::PersonShocks()
    : Person(), shock_(0), insured_(false) {}
PersonShocks::PersonShocks(int a, int h, int c)
    : Person(a, h, c), shock_(0), insured_(false) {}

void PersonShocks::Shock(int shock_size) {
  shock_ += shock_size;
  LoseHealth(shock_size);
}

void PersonShocks::Insure(int cost) {
  if (cost <= cash_) {
    cash_ -= cost;
    insured_ = true;
  }
}

void PersonShocks::ReceiveInsuranceSettlement(int cash_payment,
                                                    int health_payment) {
  cash_ += cash_payment;
  GainHealth(health_payment);
}
}  // namespace healthcare
