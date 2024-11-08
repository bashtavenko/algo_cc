// Huffman
//
//
#ifndef ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_4_HUFFMAN_H_
#define ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_4_HUFFMAN_H_

#include <string>

struct Node {
  int freq;  // Not needed for decoding
  char data;
  Node* left;
  Node* right;
};

std::string Decode(Node* root, std::string s);

#endif  // ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_4_HUFFMAN_H_
