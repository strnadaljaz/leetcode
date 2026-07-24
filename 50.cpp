#include <cstdlib>

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 1) return x;

        unsigned int k;

        if (n < 0) {
            x = 1 / x;
            k = (long)n * -1;
        }

        else 
            k = n;

        double result = 1;
        for (int i = 0; i < k; ++i) {
            result *= x;
        }

        return result;
    }
};
