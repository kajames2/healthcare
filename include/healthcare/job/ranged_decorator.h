#ifndef _HEALTHCARE_JOB_RANGED_DECORATOR_H_
#define _HEALTHCARE_JOB_RANGED_DECORATOR_H_

#include <memory>

#include "healthcare/age_range.h"
#include "healthcare/job.h"

class HealthState;

namespace healthcare {
namespace job {

class RangedDecorator : public Job {
 public:
  RangedDecorator(AgeRange range, std::unique_ptr<const Job> job);
  int GetEarnings(int age, int health) const override;

 private:
  std::unique_ptr<const Job> job_;
  AgeRange range_;
};

}  // namespace job
}  // namespace healthcare
#endif  // _HEALTHCARE_JOB_RANGED_DECORATOR_H_
