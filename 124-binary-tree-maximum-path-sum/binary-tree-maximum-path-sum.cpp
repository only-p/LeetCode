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
 int solve(TreeNode* root, int &ans) {
    if(root == NULL)
        return 0;

    int left = solve(root->left, ans);
    int right = solve(root->right, ans);

    int leftGain = max(0, left);
    int rightGain = max(0, right);

    // best path through current node
    ans = max(ans, root->val + leftGain + rightGain);

    // return best single path upward
    return root->val + max(leftGain, rightGain);
}

public:
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        solve(root,ans);
        return ans;
        
    }
};