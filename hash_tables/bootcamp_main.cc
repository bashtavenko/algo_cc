#include <gflags/gflags.h>
#include <glog/logging.h>
#include <string>
#include "absl/container/flat_hash_map.h"
#include "absl/container/flat_hash_set.h"
#include "absl/strings/str_format.h"

int32_t Run(absl::string_view s) {
  constexpr int32_t kModulus = 10;
  constexpr int32_t kMult = 997;
  int32_t val = 0;
  for (const char8_t c : s) {
    val = (val * kMult + c) % kModulus;
  }
  return val;
}

// An anagram is a word or phrase formed by rearranging the letters of a
// different word or phrase.
// "silent" = "listen"
// The point is that to find anagram the ordered characters of a strings
// produces the same hashmap.
void FindAnagrams() {
  const std::vector<std::string> dictionary{"debitcard", "elvis", "silent",
                                            "badcredit", "lives", "freedom",
                                            "listen",    "levis", "money"};
  std::vector<std::string> output;
  absl::flat_hash_map<std::string, std::vector<std::string>>
      sorted_strings_to_anagram;
  for (absl::string_view s : dictionary) {
    std::string sorted(s);                    // copy construct
    std::sort(sorted.begin(), sorted.end());  // sort characters
    sorted_strings_to_anagram[sorted].emplace_back(s);
  }

  for (const auto& p : sorted_strings_to_anagram) {
    if (p.second.size() >= 2) {
      for (const auto& v : p.second) {
        LOG(INFO) << v;
      }
    }
  }
}

struct ContactList {
  std::vector<std::string> names;

  // Better than for-loop
  bool operator==(const ContactList& that) const {
    return absl::flat_hash_set<std::string>(names.begin(), names.end()) ==
           absl::flat_hash_set<std::string>(that.names.begin(),
                                            that.names.end());
  }
};

struct HashContactList {
  // operator() ->  call operator acts a functor. HashContactList l; l("abc")
  // Requires to be put in a hash set or hash table.
  // Supposed to return hash.
  size_t operator()(const ContactList& contacts) const {
    size_t hash_code = 0;
    for (const std::string& name : absl::flat_hash_set<std::string>(
             contacts.names.begin(), contacts.names.end())) {
      hash_code ^= std::hash<std::string>()(name);
    }
    return hash_code;
  }
};

void Merge() {
  std::vector<ContactList> data = {
      ContactList{.names = {"abc", "def"}},
      ContactList{.names = {"abc", "def"}},  // dup
      ContactList{.names = {"xyz", "bbb"}},
  };

  // Requires class or struct for Hash with call operator.
  absl::flat_hash_set<ContactList, HashContactList> unique_contracts(
      data.begin(), data.end());

  for (const ContactList& contact : unique_contracts) {
    for (const auto& name : contact.names) {
      LOG(INFO) << name;
    }
  }
}

// The absl::flat_hash_map requires BOTH a hash function and an EQUALITY
// comparison for the key type.
struct Point {
 public:
  int32_t x;
  int32_t y;

  bool operator==(const Point& other) const {
    return x == other.x && y == other.y;
  }

  template <typename H>
  friend H AbslHashValue(H h, const Point& c) {
    return H::combine(std::move(h), c.x, c.y);
  }
};

void UpdateHashTable() {
  absl::flat_hash_map<Point, std::string> table;
  Point p{1, 2};
  table[p] = "foo";
  auto it = table.find(p);
  // This would not even compile.
  // it->first.x = 3;

  // This would work
  auto val = table[p];  // "Foo" {{{1, 2},"foo}
  table.erase(p);
  p.x = 4;
  table[p] = val;  // Updates {{{4, 2},"foo}

  // The best one
  table[p] = "bla";
  it = table.find(p);
  p.x = 4;
  table[p] == std::move(it->second);  // Don't need val
  table.erase(it);
}

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, /*remove_flags=*/true);
  LOG(INFO) << absl::StreamFormat("Hash: %i", Run("foo"));
  LOG(INFO) << absl::StreamFormat("Hash: %i", Run("abc"));
  FindAnagrams();
  Merge();
  UpdateHashTable();
  EXIT_SUCCESS;
}