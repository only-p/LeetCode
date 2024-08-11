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
        if (!root)
            return false;
        sum = sum - root->val;
        if (sum == 0 && root->left == NULL && root->right == NULL) {
            return true;
        } 

        return (dfs(root->left, sum) || dfs(root->right, sum)) ;
        
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, targetSum);
    }
};