class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> umap;
        for (int i = 0; i < nums.size(); i++) {
            if (umap[nums[i]] == true)
                return true;
            umap[nums[i]] = true;
        }
        return false;
    }
};