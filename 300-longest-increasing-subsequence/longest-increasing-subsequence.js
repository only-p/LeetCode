/**
 * @param {number[]} nums
 * @return {number}
 */
var lengthOfLIS = function(nums) {
    const n = nums.length;
    const memo = new Array(n).fill(-1);
    
    function lisHelper(prevIndex, currentIndex) {
        if (currentIndex === n) return 0;
        
        // If we've already computed this state, return it
        if (memo[prevIndex + 1] !== -1) return memo[prevIndex + 1];
        
        let taken = 0;
        if (prevIndex === -1 || nums[currentIndex] > nums[prevIndex]) {
            taken = 1 + lisHelper(currentIndex, currentIndex + 1);
        }
        
        const notTaken = lisHelper(prevIndex, currentIndex + 1);
        
        memo[prevIndex + 1] = Math.max(taken, notTaken);
        return memo[prevIndex + 1];
    }
    
    return lisHelper(-1, 0);
};