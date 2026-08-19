#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;

        for (int i = 0; i < flowerbed.size(); ++i) {
            if (flowerbed[i] == 0) {
                bool isLeftFree = (i == 0) || (flowerbed[i - 1] == 0);
                bool isRightFree = (i == flowerbed.size() - 1) || (flowerbed[i + 1] == 0);

                if (isLeftFree && isRightFree) {
                    flowerbed[i] = 1;
                    ++count;
                }
            }
            if (count >= n) 
                return true;
        }        

        return count >= n;
    }
};