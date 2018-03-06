#include <gtest/gtest.h>

#include <memory>

#include "healthcare/consumption/logistic.h"

namespace consumptiontests {

class ConsumptionLogisticTest : public ::testing::Test {
 public:
  ConsumptionLogisticTest() : health_(0), life_investment_(0), consumption_() {}

 protected:
  virtual void SetUp() {
    health_ = 80;
    life_investment_ = 20;
    consumption_ = std::make_unique<healthcare::consumption::Logistic>(0.05);
  }

  int health_;
  int life_investment_;
  std::unique_ptr<healthcare::consumption::Logistic> consumption_;
};

TEST_F(ConsumptionLogisticTest, GetConsumption) {
  ASSERT_DOUBLE_EQ(58.48468629040039,
                   consumption_->GetLifeEnjoyment(health_, life_investment_));
}

}  // namespace consumptiontests
