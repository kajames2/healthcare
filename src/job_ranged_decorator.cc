#include "healthcare/job_ranged_decorator.h"

#include <memory>
#include <utility>

#include "healthcare/age_range.h"

namespace healthcare {

JobRangedDecorator::JobRangedDecorator(
    AgeRange range, std::unique_ptr<const Job> job)
    : range_(range), job_(std::move(job)) {}

int JobRangedDecorator::GetEarnings(int age, int health) const {
  if (!InRange(range_, age)) {
    return 0;
  }
  return job_->GetEarnings(age, health);
}

}  // namespace healthcare
