#include "hacker_rank/one_month/week_3/insert_linked_list_node.h"
#include <memory>

SinglyLinkedListNode* InsertNodeAtPosition(SinglyLinkedListNode* list, int data,
                                           int position) {
  auto head = list;
  if (!head) {
    return std::make_shared<SinglyLinkedListNode>(data).get();
  }

  int k = 1;
  auto node = head;
  while (node && k != position) {
    node = node->next;
    ++k;
  }
  // Why in the world HackerRank has raw pointers???
  // Although it could be used with std::shared_ptr
  auto temp = new SinglyLinkedListNode(data);
  temp->next = node->next;
  node->next = temp;

  return head;
}
