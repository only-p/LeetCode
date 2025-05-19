/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortedSquares = function (nums) {
    nums = nums.map(val => val * val);
    nums.sort((a, b) => a - b);
    return nums

};