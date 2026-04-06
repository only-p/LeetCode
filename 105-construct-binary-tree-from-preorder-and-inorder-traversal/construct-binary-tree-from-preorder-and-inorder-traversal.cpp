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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& preIdx,
                    int left, int right, unordered_map<int, int>& m) {
        if (left > right)
            return NULL;
        TreeNode* root = new TreeNode(preorder[preIdx]);
        int inIdx = m[preorder[preIdx]];
        preIdx++;
        root->left = solve(preorder, inorder, preIdx, left, inIdx - 1, m);
        root->right = solve(preorder, inorder, preIdx, inIdx + 1, right, m);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < inorder.size(); i++)
            m[inorder[i]] = i;
        return solve(preorder, inorder, preIdx, 0, preorder.size() - 1, m);
    }
};