// 17.5 find the majority elements
//
// More than half the strings are repetitions of single string
//"bacaaabaac" a => 6 times
// a: 6, b:2, c:2. length: 10
//
// The key is 'more than half', that is
//"bbbbcaa" => b
// b:4, a:2, c:1. Length: 7
//
// Boyer-Moore method:
// Count 'b' and then if it's not 'b', decrease count.
// Works like magic. Good for streaming.
// Group entries into two subgroups - those containing majority element,
// and those that do not hold that majority element.
//
// Also, we can do randomized sampling.
// Brute force is a hash table, but it would require O(N) space
//
#ifndef ALGO_CC_GREEDY_MAJORITY_ELEMENT_H_
#define ALGO_CC_GREEDY_MAJORITY_ELEMENT_H_
#include <string>
#include <vector>

namespace algo {

std::string MajoritySearch(
    std::vector<std::string>::const_iterator input_stream_begin,
    const std::vector<std::string>::const_iterator input_stream_end);

}  // namespace algo

#endif  // ALGO_CC_GREEDY_MAJORITY_ELEMENT_H_
