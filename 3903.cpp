#include <algorithm>
#include <climits>
#include <vector>

int max(const int &start, const int &end, std::vector<int> &nums) {
    int m = INT_MIN;
    for (int i = start; i <= end; ++i)
        m = std::max(m, nums[i]);

    return m;
}

int min(const int &start, const int &end, std::vector<int> &nums) {
    int m = INT_MAX;
    for (int i = start; i <= end; ++i)
        m = std::min(m, nums[i]);

    return m;
}

int firstStableIndex(std::vector<int> &nums, const int &k) {
    for (int i = 0; i < nums.size(); ++i) {
        int ma = max(0, i, nums);
        int mi = min(i, nums.size() - 1, nums);

        if ((ma - mi) <= k)
            return i;
    }

    return -1;
}
