# Process vs. Threads

Process - OS level isolation unit. Owns virtual address space. Own OS resources (file descriptiors, sockets, signal
handlers). Failure is isolated – segfault kills that process.

Thread – an execution inside the process. Shares the same address space as other threads in the same process. Has its own stack, registers).
Failure affects the whole process. Thread-Local Storage (TLS). One instance per thread. Not on stack, not on heap.

## Memory layout of the process

Kernel space (hidden)
Stack (per-thread) grows down
Heap (shared) grows up
BSS (zero-initialized)
Data (globals/statics)
Text / Code segment

## Primitives
* std::thread
* mutable `absl::Mutex mu_`; // declaration vs. `std::mutex mu_`;
* std::vector<int32_t> buffer_ ABSL_GUARDED_BY(mu_); // declaration vs. GUARDED_BY(mu_)
* absl::MutexLock lock(&mu_); // vs. `std::lock_guard;`
* absl::Notification
* absl::CondVar condition_; vs.`std::condition_variable condition_`;`

Conditional variables – put threads to sleep effectively and wake them up when a condition is met.

# Basics

Mutex - the actual synchronization primitive `std::mutex mu_;`
`std::mutex` is a non-reentrant mutex. It can deadlock from the same thread that holds it.
`std::recursive_mutex` is a reentrant mutex. It can lock multiple times from the same thread.
`std::shared_mutex` readers-writer lock.

Lock - acquires and releases the mutex `std::lock_guard<std::mutex> lock(mu_);`
Lock types `std::unique_lock` or `std::scoped_lock`

## Atomic operations

Lock-free synchronization primitives
`std::atomic<int> counter{0};` - safe won't race, no locking
`load()` obtains the value `load(std::memory_order_acquire)`
`store()` replaces the value of the atomic object
`exchange()` replaces the value
`wait()` `has_value_.wait(false, std::memory_order_acquire);` blocks the thread until notified and the atomic value changes

```cpp
std::atomic<int> value{0};

value.store(42);           // Atomic write
int x = value.load();      // Atomic read
value.fetch_add(5);        // Atomic add, returns old value
value++;                   // Shorthand for fetch_add(1)

// Compare-and-swap (CAS)
int expected = 10;
value.compare_exchange_strong(expected, 20);
// If value == 10, set to 20; otherwise update expected with current value
```

Use atomic for simple counters, flags, pointers and especially for lock-free data structures.

### Memory ordering

```cpp
value.store(42, std::memory_order_relaxed);  // Fastest, no synchronization
value.store(42, std::memory_order_release);  // Release semantics
value.load(std::memory_order_acquire);       // Acquire semantics
value.store(42, std::memory_order_seq_cst);  // Default, strongest guarantees
```

# cc:thread vs. fibers

## Threads (std::thread)

* Definition: A thread is a system-level unit of execution that runs in parallel with other threads. std::thread in C++
  represents a thread managed by the operating system.
* Concurrency: Threads allow for true parallelism on multicore systems, meaning multiple threads can run
  simultaneously on different CPU cores.
* Scheduling: Threads are scheduled by the operating system, which handles the switching between threads (context
  switching). This ensures that if one thread is blocked (e.g., waiting for I/O), another can be executed.
* Preemptive Multitasking: Since the OS manages threads, it can interrupt and resume threads at any time, making thread
  execution preemptive.
* Resource Consumption: Threads are heavier in terms of resource consumption because they require their own stack and
  have more overhead due to OS scheduling. Each thread switch involves a context switch, which can be expensive.
* Shared Memory: Threads share the same memory space (within a process), which simplifies data sharing but also
  increases the risk of race conditions, requiring synchronization mechanisms like mutexes or atomic variables.

## Fibers

* Definition: Fibers are user-space units of execution, which can be thought of as lightweight threads. They rely on
  cooperative multitasking, meaning the programmer is responsible for yielding control between fibers.
* Concurrency: Fibers provide concurrent execution but not true parallelism. They allow switching between tasks (
  fibers), but only one fiber runs at any given time on a single thread.
* Scheduling: Fibers are scheduled by the application (user space) rather than the OS. The programmer explicitly yields
  control from one fiber to another, allowing them to switch at known points without OS intervention.
* Cooperative Multitasking: Fibers only switch execution when explicitly told to do so (e.g., using a yield function).
  Unlike threads, they don’t preemptively interrupt each other.
* Resource Consumption: Fibers are lighter than threads since they don’t require an OS-level context switch. They are
  more efficient in terms of memory and scheduling overhead because the context switching happens in user space.
* Shared Memory: Like threads, fibers share the same memory space, but since they run in a cooperative multitasking
  environment, synchronization is often simpler because the user controls when switches happen.

## Race Conditions and basic concurrency primitives

* Lock in consistent order
* Minimize lock duration
* Use automic operations
* Use sharable mutable state
* Use higher level primitives such as thread-safe queues
