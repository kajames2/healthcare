#include <gtest/gtest.h>

#include <memory>

#include "healthcare/job_flat.h"

class JobFlatTest : public ::testing::Test {
 public:
  JobFlatTest() : job_() {}

 protected:
  virtual void SetUp() {
    job_ = std::make_unique<healthcare::JobFlat>(85);
  }

  std::unique_ptr<healthcare::JobFlat> job_;
};

TEST_F(JobFlatTest, GetEarnings) {
  ASSERT_DOUBLE_EQ(85, job_->GetEarnings(1, 60));
  ASSERT_DOUBLE_EQ(85, job_->GetEarnings(10, 60));
}
