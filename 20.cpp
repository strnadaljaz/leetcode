#include <stack>
#include <string>

bool isValid(std::string s) {
    std::stack<char> st;

    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[')
            st.push(ch);

        else if (st.empty()) return false;

        else {
            char cc = st.top();
            st.pop();

            if (ch == ')' && st.top() != '(') return false;
            else if (ch == ']' && cc != '[') return false;
            else if (ch == '}' && cc != '{') return false;
        } 
    }

    return st.empty();
}