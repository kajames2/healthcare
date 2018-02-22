#ifndef _HEALTHCARE_JOB_RANGED_DECORATOR_H_
#define _HEALTHCARE_JOB_RANGED_DECORATOR_H_

#include <memory>

#include "healthcare/job.h"
#include "healthcare/age_range.h"

class HealthState;

namespace healthcare {
class JobRangedDecorator : public Job {
 public:
  JobRangedDecorator(AgeRange range,
                         std::unique_ptr<const Job> job);
  int GetEarnings(int age, int health) const override;

 private:
  std::unique_ptr<const Job> job_;
  AgeRange range_;
};
}  // namespace healthcare
#endif  // _HEALTHCARE_JOB_RANGED_DECORATOR_H_
