class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans=0,minL=prices[0];
        for(int i=0;i<n;i++){
            ans=max(ans,prices[i]-minL);
            minL = min(minL,prices[i]);
        }
        return ans;
    }
};