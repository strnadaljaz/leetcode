// O(n), S(1)

#include <vector>

class Solution {
  public:
    int largestAltitude(std::vector<int> &gain) {
        int altitude = 0;
        int max = 0;

        for (int &step : gain) {
            altitude += step;
            max = std::max(max, altitude);
        }

        return max;
    }
};
