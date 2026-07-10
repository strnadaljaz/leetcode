#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <cmath>

#define MOD 1000000007

using namespace std;
vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
    std::vector<int> results;

    for (auto query : queries) {
        string sub_str = s.substr(query[0], query[1] - query[0] + 1);
        sub_str.erase(remove(sub_str.begin(), sub_str.end(), '0'), sub_str.end());

        long long x = 0;

        if (!sub_str.empty()) {
            while (!sub_str.empty()) {
                x = x * 10 + (int)(sub_str[0] - '0'); 
                x %= MOD;
                sub_str.erase(0, 1);
            }
        }

        int sum = 0;

        for (int i = 0; i < sub_str.length(); ++i) {
            sum += sub_str[i] - '0';
        }

        long long result = 1LL * x * sum;

        result %= MOD;

        results.push_back(result);
    }        

    return results;
}
