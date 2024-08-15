// 12.2 Is an anonymous letter constructable?
//
// Is it possible to create a letter from the given magazine source?
//
#ifndef ALGO_CC_HASH_TABLES_LETTER_CONSTRUCTABLE_H_
#define ALGO_CC_HASH_TABLES_LETTER_CONSTRUCTABLE_H_
#include "absl/strings/string_view.h"

namespace algo {

bool IsLetterConstructable(absl::string_view letter_text,
                           absl::string_view magazine_text);

}  // namespace algo

#endif  // ALGO_CC_HASH_TABLES_LETTER_CONSTRUCTABLE_H_
