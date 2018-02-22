#include <gtest/gtest.h>

#include <memory>

#include "healthcare/job_linear.h"

class JobLinearTest : public ::testing::Test {
 public:
  JobLinearTest() : job_() {}

 protected:
  virtual void SetUp() {
    job_ = std::make_unique<healthcare::JobLinear>(0.75);
  }

  std::unique_ptr<healthcare::JobLinear> job_;
};

TEST_F(JobLinearTest, GetEarnings) {
  ASSERT_DOUBLE_EQ(45, job_->GetEarnings(1, 60));
  ASSERT_DOUBLE_EQ(45, job_->GetEarnings(10, 60));
}
