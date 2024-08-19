// 14.4 Compute the LCA in a BST.
//
// This is a lot simpler because we could use node values.
//                  10
//        5                  12
//   1       7                     17
//
//(1, 17) => 10
//
// The gist is:
// 1. Iterative from the root
// 2. As soon as we find "v1 <= tree.data < v2", then we found LCA
//

#ifndef ALGO_CC_BST_LCA_BST_H_
#define ALGO_CC_BST_LCA_BST_H_

#include <memory>
#include "bst/bst_node.h"

namespace algo {

BSTNode* FindLCA(const std::unique_ptr<BSTNode>& root, int32_t n1, int32_t n2);

};

#endif  // ALGO_CC_BST_LCA_BST_H_
