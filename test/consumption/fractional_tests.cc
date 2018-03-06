#include <gtest/gtest.h>

#include <memory>

#include "healthcare/consumption/fractional.h"

namespace consumptiontests {

class ConsumptionFractionalTest : public ::testing::Test {
 public:
  ConsumptionFractionalTest()
      : health_(0), life_investment_(0), consumption_() {}

 protected:
  virtual void SetUp() {
    health_ = 80;
    life_investment_ = 20;
    consumption_ = std::make_unique<healthcare::consumption::Fractional>(30);
  }

  int health_;
  int life_investment_;
  std::unique_ptr<healthcare::consumption::Fractional> consumption_;
};

TEST_F(ConsumptionFractionalTest, GetConsumption) {
  ASSERT_DOUBLE_EQ(32,
                   consumption_->GetLifeEnjoyment(health_, life_investment_));
}

}  // namespace consumptiontests
