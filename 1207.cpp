#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    bool uniqueOccurrences(std::vector<int> &arr) {
        std::unordered_map<int, int> hm; // number -> count
        std::unordered_set<int> seen;

        for (int &num : arr)
            hm[num]++;

        for (auto &pair : hm) {
            if (seen.count(pair.second))
                return false;

            seen.insert(pair.second);
        }

        return true;
    }
};
