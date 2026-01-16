## std::forwarding_list
* Singly-linked list
* Constant time insertion and removal from the beginning
* No random access
* Low minimal memory overhead

## std::list
* Doubly-linked list
* Same as std::forwarding_list but from both ends and also in the middle.

**Pros**:
- O(1) insert/remove **anywhere** - if you have an iterator
- Never invalidates iterators (except to erased elements)
- No reallocation

**Cons**:
- **No random access** - can't do `list[i]`
- Poor cache locality (nodes scattered in memory)
- High memory overhead (two pointers per element)
- Slow iteration

**When to use**:
- Frequent insertion/removal in the middle with stable iterators
- Need to splice lists together
- Almost never the right choice in practice

## std::deque
* Double-ended queue, not fully contiguous
* Constant time insertion and removal at both ends
* Provides random access
* Good balance between vector and list

## std::queue
* Container adapter based on std::deque. It is not a full container class.
* Truly FIFO data structure. Restricted

## std::stack
* Container adapter based on std::deque. It is not a full container class
* LIFO, restricted

## std::vector
**Continuous** memory allocation
* can access .fron() but does not have push_front(), only back  
O(1) random access. Insert at front has O(n) complexity.