#include <string>
using namespace std;

bool isDivisor(string s, string str) {
    for (int i = 0; i < str.size(); i += s.size()) {
        string sub = str.substr(i, s.size());

        if (sub != s)
            return false;
    }

    return true;
}

string gcdOfStrings(string str1, string str2) {
    if (str1[0] != str2[0])
        return "";

    string pre;
    int max_length = 0;

    for (int i = 1; pre.size() < std::min(str1.size(), str2.size()); ++i) {
        pre = str1.substr(0, i);

        if (isDivisor(pre, str1) && isDivisor(pre, str2))
            max_length = pre.size();
    }

    return str1.substr(0, max_length);
}
