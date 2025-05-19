/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortedSquares = function (nums) {
    const ans = [];
    let i = 0;
    while (i < nums.length && nums[i] < 0) i++;
    let j = i - 1;
    while (j >= 0 && i < nums.length) {
        if (Math.abs(nums[j]) > nums[i]) {
            ans.push(nums[i] * nums[i]);
            i++;
        } else {
            ans.push(nums[j] * nums[j])
            j--;
        }
    }
    while (j >= 0) {ans.push(nums[j] * nums[j--])}
    while (i < nums.length) ans.push(nums[i] * nums[i++]);
    return ans;

};