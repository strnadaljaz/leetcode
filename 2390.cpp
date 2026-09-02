#include <algorithm>
#include <iostream>
#include <stack>

std::string removeStars(std::string &s) {
    std::stack<char> stack;

    for (char &ch : s) {
        if (ch == '*')
            stack.pop();
        else
            stack.push(ch);
    }

    s = "";

    while (!stack.empty()) {
        s += stack.top();
        stack.pop();
    }

    std::reverse(s.begin(), s.end());

    return s;
}

int main(void) {
    std::string s = "erase*****";
    std::cout << "Old: " << s << std::endl;

    s = removeStars(s);

    std::cout << "New: " << s << std::endl;

    return 0;
}
