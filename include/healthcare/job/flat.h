#ifndef _HEALTHCARE_JOB_FLAT_H_
#define _HEALTHCARE_JOB_FLAT_H_

#include "healthcare/job.h"

namespace healthcare {
namespace job {

class Flat : public Job {
 public:
  explicit Flat(int job) : job_(job) {}
  int GetEarnings(int age, int health) const override { return job_; };

 private:
  int job_;
};

}  // namespace job
}  // namespace healthcare
#endif  // _HEALTHCARE_JOB_FLAT_H_
