#include "hacker_rank/one_month/week_4/huffman.h"

std::string Decode(Node* root, std::string s) {
  // There is no need to recurse
  std::string result;
  Node* current = root;
  for (const char& bit : s) {
    // Move left or right based on the bit
    if (bit == '1') {
      current = current->right;
    } else {
      current = current->left;
    }

    // Check if we've reached a leaf node
    if (!current->left && !current->right) {
      result += current->data;  // Add the character to the result
      current = root;           // Restart from the root for the next character
    }
  }

  return result;
}
