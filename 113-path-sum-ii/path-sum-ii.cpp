/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void solve(TreeNode* root,vector<vector<int>>&ans,vector<int>&path,int target){
        if(root==NULL)return;
        target -= root->val;
        path.push_back(root->val);
        if(!root->left && !root->right && target==0)ans.push_back(path);
        solve(root->left,ans,path,target);
        solve(root->right,ans,path,target);
        path.pop_back();

    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>path;
        solve(root,ans,path,targetSum);
        return ans;
        
    }
};