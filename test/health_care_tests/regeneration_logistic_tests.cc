#include "regeneration_logistic.h"
#include <gtest/gtest.h>

#include <memory>

class RegenerationLogisticTest : public ::testing::Test {
public:
  RegenerationLogisticTest()
      : health_(0)
      , health_investment_(0)
      , regen_() {}

protected:
  virtual void SetUp() {
    health_ = 80;
    health_investment_ = 20;
    regen_ = std::make_unique<healthcare::RegenerationLogistic>(100, 0.05, 2);
  }
  
  int health_;
  int health_investment_;
  std::unique_ptr<healthcare::RegenerationLogistic> regen_;
};

TEST_F(RegenerationLogisticTest, GetRegeneration) {
  ASSERT_DOUBLE_EQ(60, regen_->GetHealthRegained(health_, health_investment_));
}
