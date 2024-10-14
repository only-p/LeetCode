class Solution {
private:
    // int sol(int n, vector<int>& dp) {
    //     if (n < 2)
    //         return n;
    //     if (dp[n] != -1)
    //         return dp[n];
    //     return dp[n] = sol(n - 1, dp) + sol(n - 2, dp);
    // }

public:
    int fib(int n) {
        // vector<int> dp(n + 1, -1);
        // if(n<2)return n;
        // dp[0] = 0;
        // dp[1] = 1;
        // for (int i = 2; i <= n; i++) {
        //     dp[i] = dp[i - 1] + dp[i - 2];
        // }
        // return dp[n];
        if(n<2)return n;
        int prev1=0,prev2=1;
        int current=0;
        for(int i=2;i<=n;i++){
            current = prev1+prev2;
            prev1=prev2;
            prev2=current;
        }
        return current;
    }
};