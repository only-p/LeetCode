class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minTill = prices[0];
        int ans = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] - minTill > ans)
                ans = prices[i] - minTill;
            if (minTill > prices[i])
                minTill = prices[i];
        }
        return ans;
    }
};