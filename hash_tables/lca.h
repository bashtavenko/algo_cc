// 12.4 Compute LCA optimizing for close ancestors.
//
#ifndef ALGO_CC_HASH_TABLES_LCA_H_
#define ALGO_CC_HASH_TABLES_LCA_H_

#include "absl/types/optional.h"
#include "binary_trees/lca_parent.h"

namespace algo {

absl::optional<BinaryTreeNode*> ComputeLcaHash(BinaryTreeNode* node_0,
                                               BinaryTreeNode* node_1);

}  // namespace algo

#endif  // ALGO_CC_HASH_TABLES_LCA_H_
