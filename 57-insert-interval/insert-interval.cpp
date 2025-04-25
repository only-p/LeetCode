class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0;
        if (intervals.size() == 0) {
            ans.push_back(newInterval);
            return ans;
        }
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            ans.push_back({intervals[i][0], intervals[i][1]});
            i++;
        }
        int start = newInterval[0];
        int end = newInterval[1];
        while (i < intervals.size() && newInterval[1] >= intervals[i][0]) {
            start= min(start, intervals[i][0]);
            end = max(end, intervals[i][1]);
            i++;
        }
        ans.push_back({start, end});
        while (i < intervals.size()) {
            ans.push_back({intervals[i][0], intervals[i][1]});
            i++;
        }

        return ans;
    }
};