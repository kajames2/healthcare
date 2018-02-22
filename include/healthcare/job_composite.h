#ifndef _HEALTHCARE_JOB_COMPOSITE_H_
#define _HEALTHCARE_JOB_COMPOSITE_H_

#include <vector>

#include "healthcare/job.h"
#include "healthcare/job_ranged_decorator.h"

class HealthState;

namespace healthcare {
class JobComposite : public Job {
 public:
  JobComposite();
  int GetEarnings(int age, int health) const override;
  void AddJob(JobRangedDecorator job);

 private:
  std::vector<JobRangedDecorator> jobs_;
};
}  // namespace healthcare
#endif  // _HEALTHCARE_JOB_COMPOSITE_H_
