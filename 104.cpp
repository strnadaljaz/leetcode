#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

int depth(TreeNode *node, int d) {
    if (node == nullptr)
        return d - 1;

    return std::max(depth(node->left, d + 1), depth(node->right, d + 1));
}

int maxDepth(TreeNode *root) {
    if (root == nullptr)
        return 0;

    return depth(root, 1);
}
