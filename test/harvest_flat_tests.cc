#include <gtest/gtest.h>

#include <memory>

#include "healthcare/harvest_flat.h"

class HarvestFlatTest : public ::testing::Test {
 public:
  HarvestFlatTest() : harvest_() {}

 protected:
  virtual void SetUp() {
    harvest_ = std::make_unique<healthcare::HarvestFlat>(85);
  }

  std::unique_ptr<healthcare::HarvestFlat> harvest_;
};

TEST_F(HarvestFlatTest, GetHarvest) {
  ASSERT_DOUBLE_EQ(85, harvest_->GetHarvest(1, 60));
  ASSERT_DOUBLE_EQ(85, harvest_->GetHarvest(10, 60));
}
