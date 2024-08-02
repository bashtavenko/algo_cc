## std::forwarding_list

* Singly-linked list
* Constant time insertion and removal from the beginning
* No random access

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

Certainly! Let's summarize the differences between std::deque and std::queue, and then briefly compare all the container
types you mentioned:
std::deque vs std::queue:

std::deque (double-ended queue):

Allows insertion and deletion at both ends
Provides random access (can access elements by index)
Is a container adapter
Can be used as the underlying container for std::stack and std::queue

std::queue:

Allows insertion at one end and deletion at the other end (FIFO - First In, First Out)
Does not provide random access
Is a container adapter, typically implemented using std::deque by default
More restricted interface, focusing on queue operations

Now, let's compare all the mentioned containers:

std::forward_list:

Singly-linked list
Allows constant time insertion and removal from the beginning
No random access
Very memory efficient, but limited functionality

std::list:

Doubly-linked list
Allows constant time insertion and removal from both ends and in the middle
No random access
More memory overhead than std::forward_list, but more flexible

std::deque:

Double-ended queue
Allows constant time insertion and removal at both ends
Provides random access
Good balance between vector and list

std::stack:

LIFO (Last In, First Out) data structure
Container adapter, typically implemented using std::deque
Restricted interface for stack operations

std::queue:

FIFO (First In, First Out) data structure
Container adapter, typically implemented using std::deque
Restricted interface for queue operations

## Key differences

* std::forward_list and std::list are node-based containers, while std::deque uses a more complex internal structure.
* std::deque provides random access, while std::forward_list and std::list do not.
* std::stack and std::queue are container adapters, not full container classes themselves.
* std::forward_list is optimized for minimal memory usage and fast insertion at the front.
* std::list allows for fast insertion and removal anywhere in the container.
* std::deque balances the benefits of std::vector and std::list, providing efficient insertion/removal at both ends and
  random access

## Usage

* Need fast insertion/removal at both ends and random access? Use std::deque.
* Need LIFO behavior? Use std::stack.
* Need FIFO behavior? Use std::queue.
* Need fast insertion/removal anywhere in the container? Use std::list.
* Need minimal memory overhead and only need to insert at the front? Use std::forward_list
