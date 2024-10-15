class Solution {
private:
    int solve(vector<int>& nums, vector<int>& dp, int idx) {
        if (idx < 0)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        int taken = nums[idx] + solve(nums, dp, idx - 2);
        int notTaken = solve(nums, dp, idx - 1);
        return dp[idx] = max(taken, notTaken);
    }

public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        if (nums.size() == 1)
            return nums[0];
        int x = solve(nums, dp, nums.size() - 2);
        nums[0] = 0;
        vector<int> dp1(nums.size(), -1);
        int y = solve(nums, dp1, nums.size() - 1);
        return max(x, y);
    }
};