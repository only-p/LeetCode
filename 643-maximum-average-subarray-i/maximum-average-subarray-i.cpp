class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = INT_MIN;
        double windowsum = 0;
        int windowstart = 0;
        for (int j = 0; j < nums.size(); j++) {
            windowsum += nums[j];
            if (j >= k - 1) {
                if ((windowsum / k) > ans)
                    ans = (windowsum / k);
                windowsum -= nums[windowstart];
                windowstart++;
            }
        }
        return ans;
    }
};