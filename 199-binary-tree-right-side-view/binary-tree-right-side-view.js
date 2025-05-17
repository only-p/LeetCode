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
var rightSideView = function(root) {
    let result =[];
    if(!root)return [];
    const queue = [root];
    while(queue.length){
        let size = queue.length;
        while(size){
            let currentNode = queue.shift();
            if(currentNode.left)queue.push(currentNode.left);
            if(currentNode.right)queue.push(currentNode.right);
            if(size==1)result.push(currentNode.val);
            size--;
        }
    }
    return result;
    
};