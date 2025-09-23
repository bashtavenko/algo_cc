## std::forwarding_list

* Singly-linked list
* Constant time insertion and removal from the beginning
* No random access
* Low minimal memory overhead

## std::list

* Doubly-linked list
* Same as std::forwarding_list but from both ends and also in the middle.

## std::deque

* Double-ended queue
* Constant time insertion and removal at both ends
* Provides random access
* Good balance between vector and list

## std::queue

* Container adapter based on std::deque. It is not a full container class.
* Truly FIFO data structure. Restricted

## std::stack

* Container adapter based on std::deque. It is not a full container class
* LIFO, restricted
