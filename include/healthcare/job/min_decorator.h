#ifndef _HEALTHCARE_JOB_MIN_DECORATOR_H_
#define _HEALTHCARE_JOB_MIN_DECORATOR_H_

#include <memory>

#include "healthcare/job.h"

class HealthState;

namespace healthcare {
namespace job {

class MinDecorator : public Job {
 public:
  MinDecorator(int min, std::unique_ptr<const Job> job)
      : job_(std::move(job)), min_(min) {}
  int GetEarnings(int age, int health) const override {
    int earnings = job_->GetEarnings(age, health);
    return earnings < min_ ? min_ : earnings;
  }

 private:
  std::unique_ptr<const Job> job_;
  int min_;
};

}  // namespace job
}  // namespace healthcare
#endif  // _HEALTHCARE_JOB_MIN_DECORATOR_H_
