* contains (preferred)
* find
* count(n)
* erase

```c++
if (auto it = map.find(value); it != map.end() {
   ... it->second;
}
```

```c++
// Operator[] adds / update and returns reference
// to the mapped value no need to contains or count.
for (const auto& c : a) {
  ++char_count[c];
}

// This is helpful to get the previous value
// int old_freq = value_freq[value];
```

# Runtime complexity
Average case O(1) Insert, lookup, delete
Worst case O(n)


Load factor = number of elements / number of buckets
When the map gets too full, performance degrades:

```c++
std::unordered_map<int, int> map;
map.max_load_factor();  // Default: 1.0
// Pre-allocate to avoid rehashing
map.reserve(10000);
```

**std::map** or **std::set** 
Red-black balanced tree BST
Ordered by key