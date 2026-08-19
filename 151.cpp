#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string word = "";
        string output = "";

        for (char ch : s) {
            if (ch == ' ' && word.length() == 0) 
                continue;
            else if (ch == ' ') {
                output = word + " " + output;
                word = "";
            }
            else {
                word += ch;
            }
        } 

        if (word.length() != 0) 
            output = word + " " + output;

        output.erase(output.size() - 1 ,1);

        return output;
    }
};