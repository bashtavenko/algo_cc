#include "hacker_rank/sorting/comparator.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <algorithm>
#include <vector>

TEST(Comparator, BasicsWorks) {
  std::vector<Player> data{{"Smith", 20}, {"Jones", 15}, {"Jones", 20}};
  std::vector<Player> want{{"Jones", 20}, {"Smith", 20}, {"Jones", 15}};
  std::sort(data.begin(), data.end(), Checker::Comparator);
  EXPECT_THAT(data, want);
}

TEST(Comparator, Example1Works) {
  std::vector<Player> data{{"amy", 100},
                           {"david", 100},
                           {"heraldo", 50},
                           {"aakansha", 75},
                           {"aleksa", 150}};
  std::vector<Player> want{{"aleksa", 150},
                           {"amy", 100},
                           {"david", 100},
                           {"aakansha", 75},
                           {"heraldo", 50}};
  std::sort(data.begin(), data.end(), Checker::Comparator);
  EXPECT_THAT(data, want);
}