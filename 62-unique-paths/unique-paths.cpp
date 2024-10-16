class Solution {
private:
    int solve(vector<vector<int>>& dp, int i, int j, int m, int n) {
        if (i >= m || j >= n) {
            return 0;
        }
        if (dp[i][j] != -1)
            return dp[i][j];

        if (i == m - 1 && j == n - 1) {
            return 1;
        }
        return dp[i][j] = solve(dp, i + 1, j, m, n) + solve(dp, i, j + 1, m, n);
    }

public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // return solve(dp, 0, 0, m, n);

        for (int i = 0; i < m; i++) {
            dp[i][0] = 1; 
        }
        for (int j = 0; j < n; j++) {
            dp[0][j] = 1; 
        }
      
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};