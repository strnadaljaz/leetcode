// O(n), S(1)
#include <algorithm>
#include <climits>
#include <string>

class Solution {
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }

    int countStartingVowels(std::string &s, int right) {
        int count = 0;
        for (int i = 0; i < right; ++i) {
            if (isVowel(s[i]))
                ++count;
        }
        return count;
    }

  public:
    int maxVowels(std::string &s, int k) {
        int left = 0;
        int right = k - 1;

        int max = INT_MIN;

        int count = countStartingVowels(s, right);

        while (right < s.size()) {
            count = isVowel(s[right]) ? count + 1 : count;
            max = std::max(max, count);
            count = isVowel(s[left]) ? count - 1 : count;
            ++right;
            ++left;
        }

        return max;
    }
};
