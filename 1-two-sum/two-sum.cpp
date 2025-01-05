class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++) {
            int remainigTarget = target - nums[i];
            if (umap[remainigTarget]) {
                return {i, umap[remainigTarget] - 1};
            }
            umap[nums[i]] = i + 1;
        }
        return {};
    }
};