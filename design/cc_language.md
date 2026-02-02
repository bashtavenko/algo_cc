### Key improvements in C++11/14/17/20

**C++ 11 (major improvement)**

* Range-based for lookup ```for (auto& x : container)```
* Lambda
* Move semantics
* Smart pointers
* Variadic templates
* Uniform initialization {}
* `std::thread`, `std::mutex`
* `constexpr`
* `int32_t`

**C++ 14 (refinement)**

* `std::make_unique`
* Labmda with auto

**C++ 17 (practical improvement)**

* Structured bindings ```for auto& [x, y] = pair```
* std::optional, std::variant, std::any, inline, `std::filesystem`

**C++ 20 (Next revolution)**

* Concepts
* Ranges library
* Modules
* Three-way comparison ```<=>```
* Designated initializers
* `consteval`

### R-value vs L-value

* L-value - named identity  `int data = 3`. R-value - temp, no persistance idexity `get_one() + get_two()`
* Steal its resources instead of copy. Avoid expensive copies

```c++
class MyClass {
    int* data;
    size_t size;
    
public:
    // Move constructor
    MyClass(MyClass&& other) noexcept 
        : data(other.data), size(other.size) 
    {
        // Steal the resources
        other.data = nullptr;  // Leave other in valid state
        other.size = 0;
    }
    
    // Move assignment operator
    MyClass& operator=(MyClass&& other) noexcept {
        if (this != &other) {
            delete[] data;  // Clean up our own resources first
            
            // Steal from other
            data = other.data;
            size = other.size;
            
            // Leave other in valid state
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }    
    
    ~MyClass() {
        delete[] data;
    }
};
```

### Perfect forwarding and variadic templates.

```c++
Variadic
// Base case
void print() {}

// Recursive case
template<typename... Args>
void print(T first, Args... rest) {
    std::cout << first << " ";
    print(rest...);  // Recursive call with remaining args
}

print(1, "hello", 3.14, 'x');  // Works with any number/types
```

Perfect forwarding
Pass arguments exactly as they were received.

This ensures:

* lvalues stay lvalues
* rvalues stay rvalues
* move semantics are preserved

```c++
template<typename T>
// Forwarding reference (not rvalue reference!)
// Template deduces to forwarding reference
void wrapper(T&& arg) {  
    real_function(std::forward<T>(arg));  // Preserves lvalue/rvalue
}
```

push_back vs. emplace_back

```c++
std::vector<std::pair<int, std::string>> vec;

// Without perfect forwarding - creates temporary, then moves
vec.push_back(std::make_pair(1, "hello"));

// With perfect forwarding - constructs in-place
vec.emplace_back(1, "hello");  // Forwards arguments directly to constructor

emplace_back takes advantage of perfect forwarding

```

## RVO and NRVO

Copy elision - optimization to avoid unnecessary copies. Guaranteed from C++17

```c++
std::vector<int32_t> CreateVector() {
    return std::vector<int>{1, 2, 3}; // Returning a temporary, RVO 
}
```

## UB - undefined behavior

Occurs when the program executes code whose effect is “not specified by the standard”.

```c++
int32_t a[3] = {1, 2, 3};
int32_t x = a[3];   // UB: index 3 is past the end (valid are 0,1,2)
LOG(INFO) << "UB: " << x;
```

```c++
int32_t x1 = 2'000'000'000;
  int32_t y1 = 2'000'000'000;
  int z = x1 + y1;   // UB: signed overflow
  LOG(INFO) << "UB signed overflow: " << z;
```

ASAN, Cppcheck, PVS-Studio

## Constexpr vs consteval

`constexpr` - compile-time if all args are constant expressions. High flexibility.
`consteval` - Always compile-time, fails to compile if any arg is not constant expression. Guaranteed zero runtime cost.
Inflexible  

```c++
constexpr int32_t Square(int32_t x) { return x * x; }
int32_t runtime_val = 5;
int32_t should_be_25 = Square(runtime_val); // Runs at RUNTIME
```