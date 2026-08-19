#include <string>

class Solution {
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
            || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'
        )
            return true;

        return false;
    }

public:
    std::string reverseVowels(std::string s) {
        int left = 0, right = s.length() - 1; 

        while (left < right) {
            if (isVowel(s[left]) && isVowel(s[right])) {
                char tmp = s[left];
                s[left] = s[right];
                s[right] = tmp;
                ++left;
                --right;
            }

            if (!isVowel(s[left]))
                ++left;
            if (!isVowel(s[right]))
                --right;
        }

        return s;
    }
};