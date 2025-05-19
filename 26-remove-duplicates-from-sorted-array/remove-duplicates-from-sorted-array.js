/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function (nums) {
    let i = 0;
    let cnt = 0;
    for (let j = 1; j < nums.length; j++) {
        if (nums[i] !== nums[j]) {
            [nums[i + 1], nums[j]] = [nums[j], nums[i + 1]];
            cnt++;
            i++;
        } 

    }
    return cnt+1;


};