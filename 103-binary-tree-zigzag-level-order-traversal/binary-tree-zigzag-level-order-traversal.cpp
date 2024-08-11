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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
         if (root == NULL)
            return ans;

        queue<TreeNode*> p;
        p.push(root);
        int x =0;
        while (!p.empty()) {
            int level = p.size();
            vector<int> temp;
            for (int i = 0; i < level; i++) {
                TreeNode* node = p.front();
                p.pop();
                temp.push_back(node->val);
                if (node->left)
                    p.push(node->left);
                if (node->right)
                    p.push(node->right);
            }
            if(x%2)reverse(temp.begin(),temp.end());
            x++;
            ans.push_back(temp);
        }
        return ans;
    }
};