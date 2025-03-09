class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) {
            return size;
        }
        unordered_set<int> st;
        for (int i = 0; i < size; i++) {
            st.insert(nums[i]);
        }
        int res = 1;
        for (auto it : st) {
            int num = it;
            if (st.find(num - 1) == st.end()) {
                auto itr = st.find(num);
                int cnt = 0, n2;
                while (itr != st.end()) {
                    n2 = *itr;
                    cnt++;
                    itr = st.find(n2 + 1);
                }
                res = max(res, cnt);
            }
        }
        return res;
    }
};