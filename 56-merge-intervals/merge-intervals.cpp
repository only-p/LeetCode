class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size() ; i++) {
            if(end>=intervals[i][0]){  //overlap with next interval
                end = max(end,intervals[i][1]); // update nextend
            }else{ // if no overlap then push to ans and update with next
                ans.push_back({start,end}); 

                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};