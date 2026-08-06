class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int start = nums[0];
        int end = nums[nums.size() - 1];
        int cnt = start;
        int n = 0;
        vector<int> ans;
        cout<<start<<end;
        for (int i = start; i <= end; i++) {
            if (nums[n] == cnt) {
                n++;
                cnt++;
            } else {
                ans.push_back(i);
                cnt++;
            }
        }
        return ans;
    }
};