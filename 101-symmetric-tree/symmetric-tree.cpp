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
    bool dfs(TreeNode* left, TreeNode* right)
 {
    if (!left && !right)
        return true;
    if (!left || !right)
        return false;

    return left->val == right->val && dfs(left->left, right->right) &&
           dfs(left->right, right->left);
}

public:
bool isSymmetric(TreeNode* root) { 
    return dfs(root->left, root->right);
     }
}
;