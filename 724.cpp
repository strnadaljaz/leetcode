// O(n^2), S(1)
#include <vector>

class Solution {
    int sumOfArray(std::vector<int> &nums) {
        int count = 0;
        for (int &num : nums)
            count += num;

        return count;
    }

  public:
    int pivotIndex(std::vector<int> &nums) {

        int sumRight = sumOfArray(nums);
        int sumLeft = 0;

        for (int i = 0; i < nums.size(); ++i) {
            sumRight -= nums[i];
            if (sumLeft == sumRight)
                return i;
            sumLeft += nums[i];
        }

        return -1;
    }
};
