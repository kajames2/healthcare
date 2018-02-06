#include "consumption_increasing_decay.h"
#include <gtest/gtest.h>

#include <memory>

class ConsumptionIncreasingDecayTest : public ::testing::Test {
public:
  ConsumptionIncreasingDecayTest()
      : health_(0)
      , life_investment_(0)
      , consumption_() {}

protected:
  virtual void SetUp() {
    health_ = 80;
    life_investment_ = 20;
    consumption_ = std::make_unique<healthcare::ConsumptionIncreasingDecay>(0.05, 0.3, 50);
  }
  
  int health_;
  int life_investment_;
  std::unique_ptr<healthcare::ConsumptionIncreasingDecay> consumption_;
};

TEST_F(ConsumptionIncreasingDecayTest, GetConsumption) {
  ASSERT_DOUBLE_EQ(29.70966626494221, consumption_->GetLifeEnjoyment(health_, life_investment_));
}
