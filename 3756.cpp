#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <cmath>
using namespace std;
vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
    std::vector<int> results;

    for (auto query : queries) {
        string sub_str = s.substr(query[0], query[1] - query[0] + 1);
        sub_str.erase(remove(sub_str.begin(), sub_str.end(), '0'), sub_str.end());

        int x;

        if (sub_str.empty()) {
            x = 0;
        }
        else {
            x = stoi(sub_str);
        }

        int sum = 0;

        for (int i = 0; i < sub_str.length(); ++i) {
            sum += sub_str[i] - '0';
        }

        long long result = 1LL * x * sum;

        result %= 1000000007;

        results.push_back(result);
    }        

    return results;
}
