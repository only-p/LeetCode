class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int end = intervals[0][1];
        int start = intervals[0][0];
        for (int i = 1; i < intervals.size(); i++) {
            if (end >= intervals[i][0]) {
                end = max(end,intervals[i][1]);
            } else {
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        ans.push_back({start, end});
        return ans;
    }
};