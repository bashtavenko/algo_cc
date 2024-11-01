// Reverse linked list basics
//
#ifndef ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_3_REVERSE_LIST_H_
#define ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_3_REVERSE_LIST_H_

// This is horrible
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

class DoublyLinkedListNode {
 public:
  int data;
  DoublyLinkedListNode* next;
  DoublyLinkedListNode* prev;

  DoublyLinkedListNode(int node_data) {
    this->data = node_data;
    this->next = nullptr;
    this->prev = nullptr;
  }
};

// Horrible function
SinglyLinkedListNode* Reverse(SinglyLinkedListNode* list);

// Yet another horrible function
DoublyLinkedListNode* Reverse(DoublyLinkedListNode* head);

#endif  // ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_3_REVERSE_LIST_H_
