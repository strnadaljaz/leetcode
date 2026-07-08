#include <iostream>
#include <vector>
using namespace std;

// nums1 = [1,3], nums2 = [2]

class Solution {
public:
    double findMedianSortedVector(vector<int>& vec) {
        int size = vec.size();

        if (size == 0)
            return 0.0;

        if (size % 2 == 0) 
            return (vec[size / 2 - 1] + vec[size / 2]) / 2.0;
        else 
            return vec[size / 2];
    }


    double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
        double med1 = findMedianSortedVector(nums1);
        double med2 = findMedianSortedVector(nums2); 

        if (med1 == 0.0) return med2;
        
        if (med2 == 0.0) return med1;

        return (med1 + med2) / 2.0f;
    }
};

int main() {
    Solution solution;

    cout << solution.findMedianSortedArrays({1,3}, {2}) << endl;

    return 0;
}
