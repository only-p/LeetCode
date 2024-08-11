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
    void dfs(TreeNode *root,int currentNumber,int &ans){
        if(!root)return;
        currentNumber = currentNumber*10+root->val;
        if(!root->left && !root->right){
            ans+=currentNumber;
        }else{
            dfs(root->left,currentNumber,ans);
            dfs(root->right,currentNumber,ans);
        }
        currentNumber/=10;
    }
public:
    int sumNumbers(TreeNode* root) {
        int currentNumber=0,ans =0;
        dfs(root,currentNumber,ans);
        return ans;
        
    }
};