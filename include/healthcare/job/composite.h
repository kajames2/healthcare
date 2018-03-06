#ifndef _HEALTHCARE_JOB_COMPOSITE_H_
#define _HEALTHCARE_JOB_COMPOSITE_H_

#include <vector>

#include "healthcare/job.h"
#include "healthcare/job/ranged_decorator.h"

class HealthState;

namespace healthcare {
namespace job {

class Composite : public Job {
 public:
  Composite();
  int GetEarnings(int age, int health) const override;
  void AddJob(RangedDecorator job);

 private:
  std::vector<RangedDecorator> jobs_;
};

}  // namespace job
}  // namespace healthcare
#endif  // _HEALTHCARE_JOB_COMPOSITE_H_
