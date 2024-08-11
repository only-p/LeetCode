/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    bool dfs(TreeNode* root, int sum) {
        if (root == NULL)
            return false;
        
        if (sum-root->val == 0 && root->left == NULL && root->right == NULL) {
            return true;
        } else if (root->left == NULL && root->right == NULL)
            return false;

        if (dfs(root->left, sum - root->val) ||
            dfs(root->right, sum - root->val)) {
            return true;
        } else {
            return false;
        }
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, targetSum);
    }
};