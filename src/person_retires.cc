#include "healthcare/person_retires.h"

#include "healthcare/job.h"
#include "healthcare/person.h"
#include "healthcare/retirement_income.h"

namespace healthcare {

PersonRetires::PersonRetires() : Person(), lifetime_earnings_(0) {}

PersonRetires::PersonRetires(int a, int h, int c, int le)
    : Person(a, h, c), lifetime_earnings_(le) {}

void PersonRetires::Work(const Job* job) {
  int earnings = job->GetEarnings(age_, health_);
  cash_ += earnings;
  lifetime_earnings_ += earnings;
}

void PersonRetires::CollectRetirement(const RetirementIncome* retirement) {
  cash_ += retirement->GetIncome(age_, lifetime_earnings_);
}

}  // namespace healthcare
