#include <iostream>

class Solution {
public:
    int countSegments(std::string s) {
        if (s.empty()) return 0;

        short count = 0;

        bool is_word = false;

        for (char &c : s) {
            if (c != ' ') {
                is_word = true;
            }
            else if (c == ' ' && is_word) {
                ++count;
                is_word = false;
            }
        }

        if (s[s.length() - 1] != ' ')
            ++count;

        return count;
    }
};