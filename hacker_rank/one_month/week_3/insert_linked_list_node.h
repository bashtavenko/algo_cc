// Given the pointer to the head node of a linked list and an integer to insert
// at a certain position, create a new node with the given integer as its
// attribute, insert this node at the desired position and return the head node.
//
#ifndef ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_3_INSERT_LINKED_LIST_NODE_H_
#define ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_3_INSERT_LINKED_LIST_NODE_H_

class SinglyLinkedListNode {
 public:
  int data;
  SinglyLinkedListNode* next;

  SinglyLinkedListNode(int node_data) {
    this->data = node_data;
    this->next = nullptr;
  }

  SinglyLinkedListNode(int node_data, SinglyLinkedListNode* next) {
    this->data = node_data;
    this->next = next;
  }
};

SinglyLinkedListNode* InsertNodeAtPosition(SinglyLinkedListNode* list, int data,
                                           int position);

#endif  // ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_3_INSERT_LINKED_LIST_NODE_H_
