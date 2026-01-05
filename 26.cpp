#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int count = 1;
    
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[i-1]) {
            nums[count] = nums[i];
            ++count;
        }
    }

    return count;
}

int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    int notDuplicates = removeDuplicates(nums);
    cout << notDuplicates << endl;

    for (int i = 0; i < notDuplicates; ++i) {
        cout << nums[i] << ", ";
    }

    cout << "\n";

    return 0;
}