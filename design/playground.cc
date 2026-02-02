#include "gflags/gflags.h"
#include "glog/logging.h"
#include <type_traits>

// compile-time IIF all arguments are constexpr
// consteval fails to compile
constexpr int32_t Square(int32_t x) { return x * x; }

// SFINAE
template<typename T>
// -> SomeType specifies actual return type
auto func(int32_t) -> decltype(typename T::type{}, void()) {
  LOG(INFO) << "Has nested type";
}

template<typename T>
void func(...) {
  LOG(INFO)  << "No nested type";
}

struct HasType { using type = int32_t; };
struct NoType { };

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  FLAGS_logtostderr = 1;

  int32_t runtime_val = 5;
  int32_t should_be_25 = Square(runtime_val); // Runs at RUNTIME
  LOG(INFO) << should_be_25;

  // SFINAE
  func<HasType>(0);  // "Has nested type"
  func<NoType>(0);   // "No nested type"

  return EXIT_SUCCESS;
}