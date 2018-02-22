#include <gtest/gtest.h>

#include <iostream>
#include <memory>
#include <utility>

#include "healthcare/job_composite.h"
#include "healthcare/job_flat.h"
#include "healthcare/job_ranged_decorator.h"
#include "healthcare/age_range.h"

class JobCompositeTest : public ::testing::Test {
 public:
  JobCompositeTest() : job_() {}

 protected:
  virtual void SetUp() {
    auto job1 = std::make_unique<const healthcare::JobFlat>(5);
    auto job2 = std::make_unique<const healthcare::JobFlat>(10);
    job_.AddJob(healthcare::JobRangedDecorator(
        healthcare::AgeRange{1, 5}, std::move(job1)));
    job_.AddJob(healthcare::JobRangedDecorator(
        healthcare::AgeRange{3, 7}, std::move(job2)));
  }

  healthcare::JobComposite job_;
};

TEST_F(JobCompositeTest, GetEarnings) {
  ASSERT_EQ(0, job_.GetEarnings(0, 10));
  ASSERT_EQ(5, job_.GetEarnings(1, 10));
  ASSERT_EQ(15, job_.GetEarnings(4, 10));
  ASSERT_EQ(10, job_.GetEarnings(6, 10));
  ASSERT_EQ(0, job_.GetEarnings(8, 10));
}
