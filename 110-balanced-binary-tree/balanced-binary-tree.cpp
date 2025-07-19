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
    int dfs(TreeNode* root){
        if(!root)return 0;
        int left = 0;
        int right = 0;
        if(root->left)left = 1 + dfs(root->left);
        if(root->right)right = 1+ dfs(root->right);
        if(abs(left-right)>1){
            flag = false;
        }
        return max(left,right);
    }
public:
int flag =true;
    bool isBalanced(TreeNode* root) {
         dfs(root);
         return flag;
        
    }
};