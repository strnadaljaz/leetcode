#include <algorithm>
#include <limits.h>
#include <queue>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution { 
public:
    std::vector<int> largestValues(TreeNode* root) {
        std::vector<int> res;

        if (!root) return res; 
        
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int max_val = INT_MIN;
            int level_size = q.size();

            for (int i = 0; i < level_size; ++i) { 
                TreeNode* current = q.front();
                q.pop();

                max_val = std::max(max_val, current->val);
                
                if (current->left != nullptr) 
                    q.push(current->left);

                if (current->right != nullptr) 
                    q.push(current->right);
            }

            res.push_back(max_val);
        }

        return res;
    }
};
