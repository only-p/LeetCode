class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, ans = 0;
        unordered_map<char, int> m;
        while (j < s.size()) {
            if (m[s[j]] == 0) {
                m[s[j]] = 1;
                ans = max(ans, j - i + 1);
                j++;

            } else {
                m[s[i]] = 0;
                i++;
            }
        }
        return ans;
    }
};