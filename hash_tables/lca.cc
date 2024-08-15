#include "hash_tables/lca.h"
#include "absl/container/flat_hash_set.h"
#include "absl/types/optional.h"
#include "binary_trees/lca_parent.h"

namespace algo {

absl::optional<BinaryTreeNode*> ComputeLcaHash(
    const std::shared_ptr<BinaryTreeNode>& node_0,
    const std::shared_ptr<BinaryTreeNode>& node_1) {
  auto iter_0 = node_0;
  auto iter_1 = node_1;

  absl::flat_hash_set<BinaryTreeNode*> nodes_on_path_to_root;
  // Ascend nodes in tandem.
  // This is simpler than in lca_parent.cc because we don't need
  // to get nodes aligned to the same depth. Tradeoff - space vs time.
  // Also, it does not need to traverse all nodes all to the root.
  while (iter_0 || iter_1) {
    if (iter_0) {
      // std::unordered_set<>::emplace returns a pair of
      // iterator to the inserted element and bool == true
      // IFF the insertion took place
      if (nodes_on_path_to_root.emplace(iter_0.get()).second == false) {
        // Found in set
        return absl::make_optional<BinaryTreeNode*>(iter_0.get());
      }
      iter_0 = iter_0->parent.lock();  // Because of std::weak_ptr
    }
    if (iter_1) {
      if (nodes_on_path_to_root.emplace(iter_1.get()).second == false) {
        return absl::make_optional<BinaryTreeNode*>(iter_1.get());
      }
      iter_1 = iter_1->parent.lock();  // Because of std::weak_ptr
    }
  }
  return {};
}

}  // namespace algo