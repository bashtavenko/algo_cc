// 12.2 Is an anonymous letter constructable?
//
// Is it possible to create a letter from the given magazine source?
//
#ifndef ALGO_CC_HASH_TABLES_LETTER_CONSTRUCTABLE_H_
#define ALGO_CC_HASH_TABLES_LETTER_CONSTRUCTABLE_H_
#include <string_view>

namespace algo {

bool IsLetterConstructable(std::string_view letter_text,
                           std::string_view magazine_text);

}  // namespace algo

#endif  // ALGO_CC_HASH_TABLES_LETTER_CONSTRUCTABLE_H_
