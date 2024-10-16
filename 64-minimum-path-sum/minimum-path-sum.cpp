class Solution {
private:
    int solve(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j,
              int m, int n) {
        if (i >= m || j >= n)
            return INT_MAX;
        if (i == m - 1 && j == n - 1) {
            return grid[i][j];
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        int down = solve(grid, dp, i + 1, j, m, n);
        int right = solve(grid, dp, i, j + 1, m, n);
        return dp[i][j] = grid[i][j] + min(down, right);
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(grid, dp, 0, 0, m, n);
    }
};