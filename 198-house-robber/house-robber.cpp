class Solution {
private:
    int solve(vector<int>& nums, vector<int>& dp, int idx) {
        if (idx < 0)
            return 0;
        if(idx==0)return nums[0];
        if (dp[idx] != -1)
            return dp[idx];
        int left = solve(nums, dp, idx - 2) + nums[idx];
        int right = solve(nums, dp, idx - 1);
        return dp[idx] = max(left, right);
    }

public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);
        return solve(nums, dp, nums.size() - 1);
        // dp[0]=nums[0];
        // for (int i = 1; i < nums.size(); i++) {
            
        // }
        // return dp[nums.size() - 1];
    }
};