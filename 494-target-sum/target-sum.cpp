class Solution {
    int helper(vector<int>& nums, vector<vector<int>>& dp, int target, int index, int offset) {
        int max_sum = offset * 2;
        if (target + offset < 0 || target + offset > max_sum) {
            return 0;
        }
        if (index == nums.size()) {
            return target == 0 ? 1 : 0;
        }
        if (dp[index][target + offset] != -1) {
            return dp[index][target + offset];
        }
        int add = helper(nums, dp, target - nums[index], index + 1, offset);
        int subtract = helper(nums, dp, target + nums[index], index + 1, offset);
        return dp[index][target + offset] = add + subtract;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums) sum += num;

        // If the target is outside possible range, no solution.
        if (abs(target) > sum) return 0;

        int offset = sum;
        int max_range = 2 * sum + 1;

        vector<vector<int>> dp(nums.size(), vector<int>(max_range, -1));
        return helper(nums, dp, target, 0, offset);
    }
};
