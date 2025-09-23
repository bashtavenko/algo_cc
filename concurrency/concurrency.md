# Boilerplate

* std::thread
* mutable absl::Mutex mu_; // declaration
* std::vector<int32_t> buffer_ ABSL_GUARDED_BY(mu_); // declaration
* absl::MutexLock lock(&mu_); // definition RAII
* absl::Notification
* absl::CondVar condition_;

# cc:thread vs fibers

## Threads (std::thread)

* Definition: A thread is a system-level unit of execution that runs in parallel with other threads. std::thread in C++
  represents a thread that is managed by the operating system.
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
  fibers) but only one fiber runs at any given time on a single thread.
* Scheduling: Fibers are scheduled by the application (user space) rather than the OS. The programmer explicitly yields
  control from one fiber to another, allowing them to switch at known points without OS intervention.
* Cooperative Multitasking: Fibers only switch execution when explicitly told to do so (e.g., using a yield function).
  Unlike threads, they don’t preemptively interrupt each other.
* Resource Consumption: Fibers are lighter than threads since they don’t require an OS-level context switch. They are
  more efficient in terms of memory and scheduling overhead because the context switching happens in user space.
* Shared Memory: Like threads, fibers share the same memory space, but since they run in a cooperative multitasking
  environment, synchronization is often simpler because the user controls when switches happen.