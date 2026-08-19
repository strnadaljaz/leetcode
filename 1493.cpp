#include <vector>

// O(n), S(1)

// nums = [0,1,1,1,0,1,1,0,1]

class Solution {
  public:
    int longestSubarray(std::vector<int> &nums) {
        int left = 0, right = 0;
        int size = nums.size();
        int zero_count = 0;
        int max = 0;

        while (right < size) {
            if (nums[right] == 0)
                ++zero_count;

            while (zero_count > 1) {
                if (nums[left] == 0)
                    --zero_count;
                ++left;
            }

            max = std::max(max, right - left);
            ++right;
        }

        return max;
    }
};
