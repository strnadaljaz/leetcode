#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

TreeNode *sortedArrayToBST(vector<int> &nums, int left = 0, int right = -1) {
    if (right == -1)
        right = nums.size();

    if (left > right) 
        return nullptr;

    int middle = (left - right) / 2;
    TreeNode* curr = new TreeNode(nums[middle]);

    curr->left = sortedArrayToBST(nums, left, middle - 1);
    curr->right = sortedArrayToBST(nums, middle + 1, right);

    return curr;
}
