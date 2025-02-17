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

```c++
if (auto it = map.find(value); it != map.end() {
   ... it->second;
}
```

