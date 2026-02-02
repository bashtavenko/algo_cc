#include "gflags/gflags.h"
#include "glog/logging.h"

class EmptyClass {};

class Wrapper {
 public:
  Wrapper() { handler_ = 123; }

  // Delete copy constructor and copy assignment operator
  Wrapper(const Wrapper&) = delete;
  Wrapper& operator=(const Wrapper&) = delete;

  // Move constructor
  Wrapper(Wrapper&& other) noexcept : handler_(other.handler_) {
    other.handler_ = -1; // Reset the source object's handler
    LOG(INFO) << "Moved (constructor)";
  }

  // Move assignment operator
  Wrapper& operator=(Wrapper&& other) noexcept {
    if (this != &other) {
      handler_ = other.handler_;
      other.handler_ = -1; // Reset the source object's handler
      LOG(INFO) << "Moved (assignment)";
    }
    return *this;
  }

  ~Wrapper() {
    if (handler_ != -1) {
      LOG(INFO) << "Deallocated handler: " << handler_;
    } else {
      LOG(INFO) << "Destructor called for moved-from object";
    }
    handler_ = -1;
  }
 private:
  int32_t handler_;
};

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  FLAGS_logtostderr = 1;

  // EBO - empty base optimization
  LOG(INFO) << sizeof(EmptyClass) << " byte(s)";  // 1 byte

  LOG(INFO) << "Creating w1";
  Wrapper w1;
  
  LOG(INFO) << "Moving w1 to w2";
  Wrapper w2 = std::move(w1);  // Move (constructor)

  LOG(INFO) << "Creating w3";
  LOG(INFO) << "Moving w2 to w3";
  Wrapper w3;
  w3 = std::move(w2); // Move (assignment)

  // Undefined behavior
  int32_t a[3] = {1, 2, 3};
  int32_t x = a[3];   // UB: index 3 is past the end (valid are 0,1,2)
  LOG(INFO) << "UB: " << x;

  int32_t x1 = 2'000'000'000;
  int32_t y1 = 2'000'000'000;
  int z = x1 + y1;   // UB: signed overflow
  LOG(INFO) << "UB signed overflow: " << z;

  return EXIT_SUCCESS;
}