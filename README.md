# algo_cc

Code snippets, basic data structures, algorithms and interview problems in C++.
This was started from [EPI](https://elementsofprogramminginterviews.com/) with more modern C++, Bazel, testing and
Google styles.

## Clion

```
bazel run //:buildifier
```

ClangFormat  
Settings | Editor | Code Style
Enable ClangFormat
Run Analyze at the root

Version Control | Commit Checks

Tools | Action on Save

## GTest

MakeChange a specific test
--test_arg=--gest_filter=Diagonal.Works
