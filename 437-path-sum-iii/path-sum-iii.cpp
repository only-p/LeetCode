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
    void countPathsRecursive(TreeNode* currentNode, int S,
                             vector<int>& currentPath, int& ans) {
        if (currentNode == nullptr)
            return;

        // Add the current node to the path
        currentPath.push_back(currentNode->val);
        long pathSum = 0;

        // Find the sums of all sub-paths in the current path list
        for (int i = currentPath.size() - 1; i >= 0; i--) {
            pathSum += currentPath[i];
            // If the sum of any sub-path is equal to 'S', increment the answer
            // count
            if (pathSum == S) {
                ans++;
            }
        }

        // Traverse the left sub-tree
        countPathsRecursive(currentNode->left, S, currentPath, ans);
        // Traverse the right sub-tree
        countPathsRecursive(currentNode->right, S, currentPath, ans);

        // Remove the current node from the path to backtrack
        currentPath.pop_back();
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> currentPath;
        int ans = 0;
        countPathsRecursive(root, targetSum, currentPath, ans);
        return ans;
    }
};