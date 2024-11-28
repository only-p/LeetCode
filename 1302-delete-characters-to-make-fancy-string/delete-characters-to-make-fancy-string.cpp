class Solution {
public:
    string makeFancyString(string s) {
        int cnt = 0;
        int j = 0;
        string ans;
        ans += s[0];
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != s[j]) {
                j = i;
            } else {
                if (i - j >= 2)
                    continue;
            }
            ans += s[i];
        }
        return ans;
    }
};