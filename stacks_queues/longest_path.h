// Suppose we have a file system that stores both files and directories. An
// example of one system is represented in the following picture:
//
// dir
// ⟶ subdir1
// ⟶ ⟶ file1.ext
// ⟶ ⟶ subsubdir1
// ⟶ subdir2
// ⟶ ⟶ subsubdir2
// ⟶ ⟶ ⟶ file2.ext
// If we were to write this representation in code, it will look like this:
// "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext".
// Note that the '\n' and '\t' are the new-line and tab characters.
// Every file and directory has a unique absolute path in the file system, which
// is the order of directories that must be opened to reach the file/directory
// itself, all concatenated by '/'s. Using the above example, the absolute path
// to file2.ext is "dir/subdir2/subsubdir2/file2.ext". Each directory name
// consists of letters, digits, and/or spaces. Each file name is of the form
// name.extension, where name and extension consist of letters, digits, and/or
// spaces.
// Given a string input representing the file system in the explained format,
//    return the length of the longest absolute path to a file in the abstracted
//        file system.If there is no file in the system,
//    return 0.

#include <cstdint>
#include "absl/strings/string_view.h"

namespace algo {

int32_t LongestPath(absl::string_view path);

}  // namespace algo

#ifndef LONGEST_PATH_H
#define LONGEST_PATH_H

#endif  // LONGEST_PATH_H
