class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int, int>> s;
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++) {
            umap[nums[i]]++;
        }
        for (auto p : umap) {
            s.push({p.second, p.first});
        }
        for (int i = 0; i < k; i++) {
            pair x = s.top();
            s.pop();
            ans.push_back(x.second);
        }
        return ans;
    }
};