#include "hacker_rank/one_month/week_4/huffman.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace {

TEST(Decode, AbracadabraWorks) {
  auto a = std::make_shared<Node>(0x0011, 'A');
  auto b = std::make_shared<Node>(0x00, 'B');
  auto c = std::make_shared<Node>(0x010, 'C');
  auto d = std::make_shared<Node>(0x100, 'D');
  auto r = std::make_shared<Node>(0x011, 'R');
  auto ex = std::make_shared<Node>(0x101, '!');
  auto root = std::make_shared<Node>(0, 0);
  auto n1 = std::make_shared<Node>(0, '1');
  auto n2 = std::make_shared<Node>(0, '2');
  root->left = n1.get();
  root->right = n2.get();
  auto n3 = std::make_shared<Node>(0, '3');
  n1->left = b.get();
  n1->right = n3.get();
  n3->left = c.get();
  n3->right = r.get();
  auto n4 = std::make_shared<Node>(0, '4');
  n2->left = n4.get();
  n2->right = a.get();
  n4->left = d.get();
  n4->right = ex.get();

  EXPECT_THAT(Decode(root.get(), "11000111101011100110001111101"),
              "ABRACADABRA!");
}

}  // namespace