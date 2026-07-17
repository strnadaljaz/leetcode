#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        combinations(candidates, target, 0, candidates.size() - 1, result, {});

        reverse(result.begin(), result.end());

        return result;
    }

private:
    void combinations(const vector<int>& candidates, int target, int sum, int current, vector<vector<int>>& result, vector<int> currentRow) {
        sum += candidates[target]; 
        currentRow.push_back(candidates[target]);

        if (sum == target) {
            reverse(currentRow.begin(), currentRow.end());
            result.push_back(currentRow); 
            combinations(candidates, target, 0, candidates.size() - 1 - result.size(), result, {});
        }

        else if (sum < target) {
            combinations(candidates, target, sum, current, result, currentRow);
        }

        else {
            sum -= currentRow.back();
            currentRow.pop_back();
            combinations(candidates, target, sum, current - 1 >= 0 ? current - 1 : , result, currentRow);
        }
    } 
};