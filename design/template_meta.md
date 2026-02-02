# Template metaprogramming

## Compile-time safety

`static_assert(has_type<MyType>::value, "HasType should have ::type");`

Type safety at compile-time `std::vector<nonexistent_type>`
Bounds and preconditions
`std::enable_if_t<std::is_same_v<T,`
Type traits
`std::is_trivially_copyable_v<T>`

## SFINAE

Substitution failure is not an error

When a template argument substitutes a template declaration with an invalid type or expression, that
substitution silently fails instead of being a hard compilation error. The compiler simply discards that candidate and tries
the next overload.

```
// #1: Only valid if T has nested ::type
template<typename T>
void func(typename T::type*) { }

// #2: Catch-all
template<typename T>
void func(...) { }

struct HasType { using type = int; };
struct NoType { };

func<HasType>(nullptr);  // Uses #1 ✓
func<NoType>(nullptr);   // Uses #2 ✓ (SFINAE discards #1)
```