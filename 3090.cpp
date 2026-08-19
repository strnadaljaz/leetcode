#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int max = 0;
        int left = 0, right = 0;

        std::map<char, int> hash;
        
        while (right < s.length()) {
            hash[s[right]] += 1;

            while (hash[s[right]] > 2) {
                hash[s[left]]--;
                ++left;
            }

            ++right;

            max = std::max(max, right - left);
        }

        return max;
    }
};