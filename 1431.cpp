#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    int maxCandies(vector<int>& candies) {
        int max = candies[0];

        for (int& num : candies)
            max = std::max(max, num); 

        return max;
    }

public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = maxCandies(candies);
        vector<bool> result;

        for (int& num : candies) {
            result.push_back(num + extraCandies >= max); 
        }

        return result;
    }
};