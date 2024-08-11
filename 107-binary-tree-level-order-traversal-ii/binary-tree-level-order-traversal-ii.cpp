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
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;

        queue<TreeNode*> pq;
        pq.push(root);
        while (!pq.empty()) {
            int levelsize = pq.size();
            vector<int> temp;
            for (int i = 0; i < levelsize; i++) {
                TreeNode* node = pq.front();
                pq.pop();
                temp.push_back(node->val);
                if (node->left)
                    pq.push(node->left);
                if (node->right)
                    pq.push(node->right);
            }
            ans.push_back(temp);
        }
         reverse(ans.begin(),ans.end());
         return ans;
    }
};