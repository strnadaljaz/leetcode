#include <algorithm>
#include <climits>
#include <vector>

class Solution {
  public:
    int maxArea(std::vector<int> &height) {
        int left = 0, right = height.size() - 1;

        int max = INT_MIN;

        while (left < right) {
            int area = (right - left) * std::min(height[left], height[right]);

            max = std::max(max, area);

            if (height[left] < height[right])
                ++left;
            else
                --right;
        }

        return max;
    }
};
