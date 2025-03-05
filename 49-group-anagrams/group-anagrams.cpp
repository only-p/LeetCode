class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        vector<vector<string>> ans;
        for (auto word : strs) {
            string sorted_word = word;
            sort(sorted_word.begin(), sorted_word.end());
            umap[sorted_word].push_back(word);
        }
        for (auto x : umap) {
            ans.push_back(x.second);
        }
        return ans;
    }
};