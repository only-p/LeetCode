/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var inorderTraversal = function (root) {
    const ans = [];
    function dfs(root) {
        if (!root) return null;
        if (root.left) {
            let left = dfs(root.left);
        }
        ans.push(root.val);
        if (root.right) {
             dfs(root.right);

        }

    }
    dfs(root)
    return ans

};