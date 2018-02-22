#include "healthcare/job_composite.h"

#include <memory>
#include <utility>
#include <vector>

#include "healthcare/job_ranged_decorator.h"


namespace healthcare {
JobComposite::JobComposite() : jobs_() {}

int JobComposite::GetEarnings(int age, int health) const {
  int net_job = 0;
  for (auto& job : jobs_) {
    net_job += job.GetEarnings(age, health);
  }
  return net_job;
}

void JobComposite::AddJob(JobRangedDecorator job) {
  jobs_.push_back(std::move(job));
}

}  // namespace healthcare
