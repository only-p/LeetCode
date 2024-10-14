class Solution {
private:
    int sol(int n, vector<int>& dp) {
        if (n <= 2)
            return n;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = sol(n - 1, dp) + sol(n - 2, dp);
    }

public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        // return sol(n,dp);
        // if (n <= 2)
        //     return n;
        // return climbStairs(n - 1) + climbStairs(n - 2);

        if (n <= 2)
            return n;
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};