#include "hacker_rank/one_month/week_3/reverse_list.h"
#include <functional>
#include <memory>

SinglyLinkedListNode* Reverse(SinglyLinkedListNode* list) {
  auto dummy_head = std::make_shared<SinglyLinkedListNode>(0);
  dummy_head->next = list;
  auto head = dummy_head;
  auto iter = head->next;
  while (iter->next) {
    auto temp = iter->next;
    iter->next = temp->next;
    temp->next = head->next;
    head->next = temp;
  }
  return dummy_head->next;
}

DoublyLinkedListNode* Reverse(DoublyLinkedListNode* head) {
  DoublyLinkedListNode* current = head;
  DoublyLinkedListNode* new_head = nullptr;

  while (current) {
    std::swap(current->next, current->prev);
    new_head = current;
    current = current->prev;
  }

  return new_head;
}