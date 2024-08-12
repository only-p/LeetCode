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
    int ans =0;
    private:
    int dfs(TreeNode* root){
        if(!root){
            return 0;
        }
        int leftHeight = dfs(root->left);
        int rightHeight = dfs(root->right);
        int diameter = leftHeight + rightHeight+1;
        ans = max(ans,diameter);
        return max(leftHeight,rightHeight)+1;

    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
         dfs(root);
         return ans-1;
       
        
    }
};