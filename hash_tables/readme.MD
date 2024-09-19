## Lookup

* contains (preferred)
* find
* count(n)

```c++
// Operator[] adds / update and returns reference
// to the mapped value no need to contains or count.
for (const auto& c : a) {
  ++char_count[c];
}

// This is helpful to get the previous value
// int old_freq = value_freq[value];
```
