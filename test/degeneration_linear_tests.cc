#include <gtest/gtest.h>

#include <memory>

#include "healthcare/degeneration_linear.h"

class DegenerationLinearTest : public ::testing::Test {
 public:
  DegenerationLinearTest() : degen_() {}

 protected:
  virtual void SetUp() {
    degen_ = std::make_unique<healthcare::DegenerationLinear>(10, 3);
  }

  int age_;
  std::unique_ptr<healthcare::DegenerationLinear> degen_;
};

TEST_F(DegenerationLinearTest, GetDegeneration) {
  ASSERT_EQ(22, degen_->GetDegeneration(4, 10));
}
