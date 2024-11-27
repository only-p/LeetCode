class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        vector<int> ans(2);
        for (int i = 0; i < nums.size(); i++) {
            int newTarget = target - nums[i];
            if (umap[newTarget]) {
                ans[0] = i;
                ans[1] = umap[newTarget] - 1;
                return ans;
            } else {
                umap[nums[i]] = i + 1;
            }
        }

        return ans;
    }
};