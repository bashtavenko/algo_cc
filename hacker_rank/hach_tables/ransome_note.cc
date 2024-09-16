#include "hacker_rank/hach_tables/ransome_note.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

bool CheckMagazine(const std::vector<std::string>& magazine,
                   const std::vector<std::string>& note) {
  if (note.size() > magazine.size()) return false;

  // Find character count in the note
  std::unordered_map<std::string, int> note_count;
  for (const std::string& word : note) {
    ++note_count[word];
  }

  // See if this is sufficient in the magazine
  for (const std::string& word : magazine) {
    if (auto it = note_count.find(word); it != note_count.end()) {
      --it->second;
      if (it->second == 0) {
        note_count.erase(word);
        // If we found all words that we need, we are done.
        if (note_count.empty()) return true;
      }
    }
  }

  return note_count.empty();
}