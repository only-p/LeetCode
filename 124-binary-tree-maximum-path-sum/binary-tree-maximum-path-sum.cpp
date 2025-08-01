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
public:
int ans =INT_MIN;
    int dfs(TreeNode* root){
        if(!root)return 0;
        int left =0;
        int right =0;
        if(root->left) left = max(0,dfs(root->left));
        if(root->right) right=  max(0,dfs(root->right));
        ans = max(ans,left+right+root->val);
        return root->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
        
    }
};