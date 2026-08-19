#include <string>

/*
 * Given two strings s and t, return true if s is a subsequence of t, or false
otherwise.

A subsequence of a string is a new string that is formed from the original
string by deleting some (can be none) of the characters without disturbing the
relative positions of the remaining characters. (i.e., "ace" is a subsequence of
"abcde" while "aec" is not).*/

class Solution {
  public:
    bool isSubsequence(std::string s, std::string t) {
        int index1 = 0, index2 = 0;

        while (index1 < s.length() && index2 < t.length()) {
            if (s[index1] == t[index2])
                ++index1;
            ++index2;
        }

        return index1 == s.length();
    }
};
