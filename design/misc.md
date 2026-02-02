## Cache

L1 is the fastest / smallest (CPU core)
L2 is bigger/slower (near the core)
L3 is the largest/slowest (shared across cores)

Cache coherency – consistency of shared data stored in multiple local caches

### Cache-friendly code and performance code
Modern CPU have hardware prefetchers.
`std::vector` store data contiguously

AOS (array of structures) `std::vector<Point`
is better than SOA (structure of arrays)
`std::vector<float> x, y is SOA

```c++
// AOS accessing ALL fields of ONE object
const users = [
  {id: 1, name: "Alice", score: 100},
  {id: 2, name: "Bob", score: 200}
];

// ONE field across MANY objects
const users = {
  ids: [1, 2, 3, ...],
  names: ["Alice", "Bob", "Charlie", ...],
  scores: [100, 200, 300, ...]
};
// Iterating over scores - better cache locality
```

```cpp
// Cache-friendly (Row-major)
for (int i = 0; i < rows; ++i)
    for (int j = 0; j < cols; ++j)
        sum += matrix[i][j];

// Cache-unfriendly (Column-major)
for (int j = 0; j < cols; ++j)
    for (int i = 0; i < rows; ++i)
        sum += matrix[i][j];
```

To write high-performance code:

1. Prefer contiguous memory (arrays, vectors) over linked structures.
2. Respect cache lines (avoid false sharing).
3. Optimize layout to minimize padding and maximize spatial locality.
4. Process data in order to help the hardware prefetcher.

## Profiling
https://github.com/google/pprof

## REST, gRPC
REST (synchronous request-response, text-based (JSON / XML), **caching**, stateless, wide tooling support)
gRPC (request-response, server screaming, client streaming, bidirectional streaming, HTTP/2, strongly typed, 5-10 times
faster than REST)
Message Queues (Kafka, RabbitMQ) – asynchronous request-response, can have two queues for each direction

### CAP
C – Consistency: Every Read receives the most recent Write (or an error). All nodes see the same data at the same time.
A - Availability: Every request receives a response (without a guarantee it's the most recent data). System remains
operational even if nodes fail.
P – Partition Tolerance: System continues operating despite network partitions (nodes can't communicate). CP or AP.
CP – MongoDB, HBase - dashboard requires a consistent view 
AP – Cassandra, DynamoDB – accepts all Writes for all sensors

CA exists on a single node without replication.

Partition tolerance is mandatory (for distributed systems) – the choice is consistency vs. availability
For non-distributed systems, CA is possible

## Scaling 10-x grows
1. Identify bottlenecks first (CPU, memory, network, database query times, queue depths)
2. Stateless components (application servers, API gateways, workers processes) - horizontal scaling, more machines
3. Stateful components (databases, caches, message queues) - bigger machines

## Backpressure strategy
1. Buffering. Only works for temporary slowdowns.
2. Flow control (slow down producer). a) Block / Wait b) rate limiter
3. Drop/sample data (lossy). Sampling is a good idea for high-volume data.
4. Push back signal (reactive flow control). Upstream components monitor downstream health
5. Load shedding (priority-based)

## Caching strategy for a high-volume workload
* LRU (Least Recently Used) – good eviction policy for read-heavy workloads
* LFU (Least Frequently Used), TTL, size-bazed, priority-based
* Data layout optimization AOS
* Distributed cache

Application level (L1) – LRU
Distributed cache (L2) - Redis/Memcached
CDN (Edge cache) – static assets, read-heavy

## SQL vs NoSQL
Types:
* OLTP (Online Transaction Processing): PostgreSQL, MySQL
* OLAP (Online Analytical Processing): Snowflake, BigQuery, Redshift

SQL analytics 
Pros – complex joins, ad-hoc queries, window functions, ACID guarantees
Cons – schema rigidity, vertical scaling, join performance, write scalability

NoSQL
1. Column-stores (Cassandra, HBase)
2. Document-stores (MongoDB, Couchbase)

Use NoSQL for real-time analytics, known specific patterns

## Sharding
Shard 1: users A-M
Shard 2: users N-Z
Shard 3: archive

## At-least-once delivery and idempotency

### At-least-once semantics
Message is processed at least once but possibly multiple times.
System will retry sending or processing a message until it is acknowledged. 

This avoids data loss, but consumers must be able to tolerate duplicate messages.

### Idempotency
A request can be processed multiple times without changing the result.

`set status=PAID”` idempotent
`balance += 100` not idempotent

## Blocking vs non‑blocking sockets

### Blocking sockets
`recv()` or `send()` do no return utill the data is available, buffer is ready, or error
Simplifies code but scales poorly with the number of connections

### Non-blocking sockets
Calls return immediately; if the operation blocks,
they fail with an error such as `EWOULDBLOCK` / `EAGAIN`

### IOCP
I/O completion ports (IOCP) are a Windows-specific mechanism for handling I/O completion notifications.

## Empty base Optimization (EBO)
Every object must have a non-zero size.

## Rule of 5
1.Destructor
2.Copy constructor
3.Copy assignment operator
3.Move constructor
5.Move assignment operator