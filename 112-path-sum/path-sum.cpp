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
    bool solve(TreeNode* root, int sum) {
        if (root == NULL)
            return false;
        sum = sum - root->val;
        if (sum == 0 && root->left == NULL && root->right == NULL)
            return true;

        return (solve(root->left, sum) || solve(root->right, sum));
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root, targetSum);
    }
};