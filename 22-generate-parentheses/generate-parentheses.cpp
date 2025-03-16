class Solution {
public:
    void solve(int n, int open, int close, string path, vector<string>& ans) {
        if (open == n && close == n) {
            ans.push_back(path);
        }
        if (open < n) {
            solve(n, open + 1, close, path + "(", ans);
        }
        if (open > close) {
            solve(n, open, close + 1, path + ")", ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string path;
        solve(n, 0, 0, "", ans);
        return ans;
    }
};