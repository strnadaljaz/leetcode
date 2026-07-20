#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        for (int i = 0; i < k; ++i) {
            int prev = grid[0][0];
            for (int j = 0; j < grid.size(); ++j) { 
                int k = j == 0 ? 1 : 0;
                for (; k < grid[j].size(); ++k) {
                    int tmp = grid[j][k];
                    grid[j][k] = prev;
                    prev = tmp;
                }
            }
            grid[0][0] = prev;
        } 

        return grid; 
    }
};