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
    void levelOrder(TreeNode * root,vector<vector<int>>&ans,int level){
        if(root==NULL)return;
        if(level>=ans.size())ans.push_back({});
        ans[level].push_back(root->val);
        levelOrder(root->left,ans,level+1);
        levelOrder(root->right,ans,level+1);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        levelOrder(root,ans,0);
        return ans;
    }
};