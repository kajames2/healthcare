#include "degeneration_linear.h"
#include "health_state.h"
#include <gtest/gtest.h>

#include <memory>

class DegenerationLinearTest : public ::testing::Test {
public:
  DegenerationLinearTest()
      : period_(0)
      , degen_() {}

protected:
  virtual void SetUp() {
    period_ = 4;
    degen_ = std::make_unique<healthcare::DegenerationLinear>(10,3);
  }
  
  int period_;
  std::unique_ptr<healthcare::DegenerationLinear> degen_;
};

TEST_F(DegenerationLinearTest, GetDegeneration) {
  ASSERT_EQ(22, degen_->GetDegeneration(period_));
}
