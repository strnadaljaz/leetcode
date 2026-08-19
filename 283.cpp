#include <utility>
#include <vector>

class Solution {
  public:
    void moveZeroes(std::vector<int> &nums) {
        if (nums.size() == 1)
            return;

        int left = 0;
        int right = 1;

        while (right < nums.size()) {
            if (nums[left] == 0 && nums[right] == 0)
                ++right;
            else {
                if (nums[left] == 0) {
                    std::swap(nums[left], nums[right]);
                }
                ++left;
                ++right;
            }
        }
    }
};
