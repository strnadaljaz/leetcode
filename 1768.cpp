#include <iostream>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int index = 0;
        string str = "";

        for (; index < word1.length() && index < word2.length(); index++) {
            str += word1[index];
            str += word2[index];
        }

        str += index == word1.length() ? word2.substr(index) : word1.substr(index);

        return str;
    }
};