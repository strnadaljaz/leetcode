#include <iostream>
#include <vector>
using namespace std;

bool inVector(int item, vector<int> nums) {
    for (int num : nums) {
        if (num == item) return true;
    }

    return false;
}

int removeDuplicates(vector<int>& nums) {
    vector<int> found = {};
    int removed = 0;

    for (int i = 0; i < nums.size()-removed; ++i) {
        if (!inVector(nums[i-removed], found)) {
            // found.resize(found.size()+1);
            found.push_back(nums[i-removed]);
        }
        else {
            // remove item
            for (int k = i-removed; k < nums.size()-removed-1; k++) {
                nums[k] = nums[k+1];
            }
            ++removed;
        }
    }    

    return (nums.size()-removed);
}

int main() {
    vector<int> nums = {1,1,2};

    int notDuplicates = removeDuplicates(nums);
    cout << notDuplicates << endl;

    for (int i = 0; i < notDuplicates; ++i) {
        cout << nums[i] << ", ";
    }

    cout << "\n";

    return 0;
}