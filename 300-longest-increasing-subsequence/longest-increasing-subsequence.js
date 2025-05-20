/**
 * @param {number[]} nums
 * @return {number}
 */
var lengthOfLIS = function(nums) {
   const n = nums.length;
    // Create a 2D memo table: memo[currentIdx][prevIdx+1]
    // We use prevIdx+1 because prevIdx can be -1 initially
    const memo = Array.from({ length: n }, () => 
                new Array(n + 1).fill(-1));
    
    function lisHelper(currentIdx, prevIdx) {
        if (currentIdx === n) return 0;
        
        // Check if already computed
        if (memo[currentIdx][prevIdx + 1] !== -1) {
            return memo[currentIdx][prevIdx + 1];
        }
        
        let take = 0;
        if (prevIdx === -1 || nums[currentIdx] > nums[prevIdx]) {
            take = 1 + lisHelper(currentIdx + 1, currentIdx);
        }
        
        const skip = lisHelper(currentIdx + 1, prevIdx);
        
        memo[currentIdx][prevIdx + 1] = Math.max(take, skip);
        return memo[currentIdx][prevIdx + 1];
    }
    
    return lisHelper(0, -1);
};