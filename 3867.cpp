#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<unsigned short> prefixGcd;

        int mx = 0;

        for (unsigned int i = 0; i < nums.size(); ++i) {
            mx = max(mx, nums[i]);
            
            prefixGcd.push_back(gcd(nums[i], mx));
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        unsigned int left = 0;
        unsigned int right = prefixGcd.size() - 1;

        vector<unsigned short> gcds;
        
        for (; left < right; ++left, --right) {
            gcds.push_back(gcd(prefixGcd[left], prefixGcd[right]));
        }

        return accumulate(gcds.begin(), gcds.end(), 0LL);
    }
};