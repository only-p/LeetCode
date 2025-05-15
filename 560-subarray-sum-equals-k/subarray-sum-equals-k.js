/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarraySum = function (nums, k) {
    const prefix = {};
    let ans = 0;
    let currentSum = 0;
    prefix[0] = 1;
    for (let i = 0; i < nums.length; i++) {
        currentSum += nums[i];
        const target = currentSum-k;
        if (prefix[target]) {
            ans += prefix[target];
        }
        if (!prefix[currentSum]) prefix[currentSum] = 0;
        prefix[currentSum]++;
    }
    console.log(prefix)
    return ans;



};