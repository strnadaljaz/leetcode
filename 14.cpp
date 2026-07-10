#include <string>
#include <vector>
#include <climits>

std::string longestCommonPrefix(std::vector<std::string>& strs) {
    int shortest_string = INT_MAX;
    
    for (auto str : strs) {
        if (str.length() < shortest_string) 
            shortest_string = str.length();
    }

    std::string prefix = "";

    for (int i = 0; i < shortest_string; ++i) {
        char c = strs[0][i];
        for (auto str: strs) {
            if (str[i] != c)
                return prefix;
        }
        prefix += c;
    }
    return prefix;
}
