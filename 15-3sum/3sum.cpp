class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            int l = i + 1, r = nums.size() - 1;

            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            while (l < r) {
                int sum = nums[l] + nums[r] + nums[i];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[r], nums[l]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1])
                        l++;

                } else if (sum > 0) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return ans;
    }
};