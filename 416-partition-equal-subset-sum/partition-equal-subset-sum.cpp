class Solution {
private:
    bool helper(vector<int>& nums, int index, int sum,
                vector<vector<int>>& dp) {
        if (index >= nums.size())
            return false;
        if (sum == 0)
            return true;
        if (dp[index][sum] != -1)
            return dp[index][sum];
        bool p1 = false;
        if (sum >= nums[index]) {
            p1 = helper(nums, index + 1, sum - nums[index], dp);
        }
        bool p2 = helper(nums, index + 1, sum, dp);
        return dp[index][sum] = p1 || p2;
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (nums.size() < 2)
            return false;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2)
            return false;
        sum = sum / 2;
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        // with only one number, we can form a subset only when the required sum
        // is equal to its value
        for (int s = 1; s <= sum; s++) {
            dp[0][s] = (nums[0] == s ? true : false);
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= sum; j++) {
                dp[i][j] = dp[i - 1][j];
                if (nums[i] <= j) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i]];
                }
            }
        }
        return dp[n - 1][sum];

        // return helper(nums,0,sum,dp);
    }
};