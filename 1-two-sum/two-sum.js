/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
    const map = new Map();
    const ans = []
    for (let i = 0; i < nums.length; i++) {
        const newTarget = target - nums[i];
        if (map.has(newTarget)) {
            return [map.get(newTarget), i];
        }
        else {
            map.set(nums[i], i)
        }
    }
    return []
};