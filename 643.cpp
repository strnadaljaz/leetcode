#include <climits>
#include <vector>

class Solution {
    int calcFirstSum(std::vector<int> &nums, int k) {
        int sum = 0;
        for (int i = 0; i < k - 1; ++i) {
            sum += nums[i];
        }

        return sum;
    }

  public:
    double findMaxAverage(std::vector<int> &nums, int k) {
        int left = 0;
        int right = k - 1;

        double max = INT_MIN;
        int sum = calcFirstSum(nums, k);

        while (right < nums.size()) {
            sum += nums[right];
            max = std::max(max, (double)sum / k);
            sum -= nums[left];
            ++left;
            ++right;
        }

        return max;
    }
};
