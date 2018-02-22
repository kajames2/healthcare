#include <gtest/gtest.h>

#include <iostream>
#include <memory>
#include <utility>

#include "healthcare/harvest_composite.h"
#include "healthcare/harvest_flat.h"
#include "healthcare/harvest_ranged_decorator.h"
#include "healthcare/age_range.h"

class HarvestCompositeTest : public ::testing::Test {
 public:
  HarvestCompositeTest() : harvest_() {}

 protected:
  virtual void SetUp() {
    auto harvest1 = std::make_unique<const healthcare::HarvestFlat>(5);
    auto harvest2 = std::make_unique<const healthcare::HarvestFlat>(10);
    harvest_.AddHarvest(healthcare::HarvestRangedDecorator(
        healthcare::AgeRange{1, 5}, std::move(harvest1)));
    harvest_.AddHarvest(healthcare::HarvestRangedDecorator(
        healthcare::AgeRange{3, 7}, std::move(harvest2)));
  }

  healthcare::HarvestComposite harvest_;
};

TEST_F(HarvestCompositeTest, GetHarvest) {
  ASSERT_EQ(0, harvest_.GetHarvest(0, 10));
  ASSERT_EQ(5, harvest_.GetHarvest(1, 10));
  ASSERT_EQ(15, harvest_.GetHarvest(4, 10));
  ASSERT_EQ(10, harvest_.GetHarvest(6, 10));
  ASSERT_EQ(0, harvest_.GetHarvest(8, 10));
}
