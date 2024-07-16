class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            int left = i + 1, right = nums.size() - 1;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            while (left < right) {
                int s = nums[left] + nums[right];
                if (s == target) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                } else if (s > target) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        return ans;
    }
};