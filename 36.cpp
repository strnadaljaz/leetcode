#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct BoxIndex {
    int x;
    int y;

    BoxIndex(int x, int y) : x(x), y(y) {}
};

class Solution {
  public:
    bool isValidSudoku(vector<vector<char>> &board) {
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                if (board[row][col] == '.')
                    continue;

                if (!isValid(board, row, col)) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isValid(vector<vector<char>> &board, int row, int col) {
        char num = board[row][col];

        // Check rows and columns
        for (int i = 0; i < 9; ++i) {
            if (board[i][col] == num && i != row)
                return false;
            if (board[row][i] == num && i != col)
                return false;
        }
        
        BoxIndex boxIndex = getBoxIndex(row, col);

        for (int i = boxIndex.x * 3; i < boxIndex.x * 3 + 3; ++i) {
            for (int j = boxIndex.y * 3; j < boxIndex.y * 3 + 3; ++j) {
                if (num == board[i][j] && !(i == row && j == col))
                    return false;
            }
        }

        return true;
    }

    BoxIndex getBoxIndex(int &row, int &col) {
        return BoxIndex(row / 3, col / 3);
    }
};
