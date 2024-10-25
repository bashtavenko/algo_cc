// Julius Caesar protected his confidential information by encrypting it using a
// cipher. Caesar's cipher shifts each letter by a number of letters. If the
// shift takes you past the end of the alphabet, just rotate back to the front
// of the alphabet. In the case of a rotation by 3, w, x, y and z would map to
// z, a, b and c.
//

#ifndef ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_2_CAESAR_CIPHER_H_
#define ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_2_CAESAR_CIPHER_H_

#include <string>

std::string CaesarCipher(const std::string& s, int k);

#endif  // ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_2_CAESAR_CIPHER_H_
