class Solution {
    private:
    int sol(int n, vector<int>&dp){
        if(n<2)return n;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=sol(n-1,dp)+sol(n-2,dp);
    }
public:
    int fib(int n) {
       vector<int>dp(n+1,-1);
       return sol(n,dp);
        
    }
};