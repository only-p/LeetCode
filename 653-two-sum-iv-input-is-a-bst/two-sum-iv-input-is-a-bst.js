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
 * @param {number} k
 * @return {boolean}
 */
var findTarget = function (root, k) {
    const arr = []
    function dfs(node) {
        if (!node) return;
        dfs(node.left);
        arr.push(node.val);
        dfs(node.right)
    }
    dfs(root);
    let i = 0;
    let j = arr.length - 1;
    while (i < j) {
        let current = arr[i] + arr[j];
        if (current === k) return true;
        if (current > k) j--;
        else i++;
    }
    return false;

};