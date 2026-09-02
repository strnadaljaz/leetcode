#include <map>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>> findDifference(std::vector<int> &nums1,
                                                 std::vector<int> &nums2) {
        std::vector<std::vector<int>> output = {{}, {}};
        std::map<int, int> hm1, hm2;

        for (int num : nums1)
            if (!hm1[num])
                hm1[num] = 1;

        for (int num : nums2) {
            if (!hm2[num])
                hm2[num] = 1;
        }

        for (auto &pair : hm1) {
            int key = pair.first;

            if (!hm2[key])
                output[0].push_back(key);
        }

        for (auto &pair : hm2) {
            int key = pair.first;

            if (!hm1[key])
                output[1].push_back(key);
        }

        return output;
    }
};
