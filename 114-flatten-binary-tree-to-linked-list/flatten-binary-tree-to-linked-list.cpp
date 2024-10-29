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
private:
    TreeNode* prev = nullptr;  // Keeps track of the previous node in the traversal

    void dfs(TreeNode* node) {
        if (!node) return;

        // Traverse right subtree first, then left subtree
        dfs(node->right);
        dfs(node->left);

        // Flatten current node
        node->right = prev;
        node->left = nullptr;
        prev = node;  // Move prev to the current node
    }


public:
    void flatten(TreeNode* root) {
        // TreeNode* node = root;
        dfs(root);
    }
};