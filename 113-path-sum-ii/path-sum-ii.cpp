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
    void dfs(TreeNode* root, int sum, vector<int>& currentPath,
             vector<vector<int>>& ans) {
        if (!root)
            return;
        currentPath.push_back(root->val);

        if (sum == root->val && !root->left && !root->right) {
            ans.push_back(currentPath);

        } else {
            dfs(root->left, sum - root->val, currentPath, ans);
            dfs(root->right, sum - root->val, currentPath, ans);
        }
        currentPath.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> currentPath;
        dfs(root, targetSum, currentPath, ans);
        return ans;
    }
};