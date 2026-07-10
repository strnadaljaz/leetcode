#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;

vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
    vector<bool> results;

    vector<int> groups(n, 0);
    int curr_group = 0;

    for (int i = 1; i < n; ++i) { 
        if (nums[i] - nums[i - 1] > maxDiff) {
            ++curr_group;
        }
        groups[i] = curr_group;
    }

    for (auto& query : queries) {
        results.push_back(groups[query[0]] == groups[query[1]]);
    }

    return results;
}
