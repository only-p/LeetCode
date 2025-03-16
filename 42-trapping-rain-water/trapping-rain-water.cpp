class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n, 0), right(n, 0);
        int maxL = height[0], maxR = height[n - 1];
        left[0] = height[0];
        right[n - 1] = height[n - 1];
        for (int i = 0; i < n; i++) {

            maxL = max(maxL, height[i]);
            left[i] = maxL;

            maxR = max(maxR, height[n - i - 1]);
            right[n - i - 1] = maxR;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += min(left[i], right[i]) - height[i];
        }
        return ans;
    }
};