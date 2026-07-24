#include <cstdlib>
#include <vector>
#include <string>

class Solution {
    bool isAttacked(std::vector<int> x, int k) {
        int i = 0;
        while (i < k) {
            if (((x[i] == x[k]) || (abs(x[i] - x[k]) == abs(i - k))) && (x[i] != -1 && x[k] != -1))
                return true;

            ++i;
        } 

        return false;
    }

public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        if (n == 1) 
            return {{"Q"}};
        
        if (n == 2 || n == 3) 
            return {{}};

        std::vector<int> x(n, -1); // here i will store n-th queen's column on index n-1

        for (int row = 0; row < n;) {
            int column = x[row] == -1 ? 0 : x[row];
            for (; column < n; ++column) {
                x[row] = column;
                if (!isAttacked(x, row))
                    break;
            }

            if (column < n) 
                ++row;
            else
                --row;
        } 

        std::vector<std::vector<std::string>> res(1);
        for (int i = 0; i < n; ++i) {
            std::string one_row = "";
            for (int k = 0; k < n; ++k) {
                if (k == x[i]) one_row += "Q";
                else one_row += ".";
            }
            res[0].push_back(one_row);
        }

        return res;
    }
};