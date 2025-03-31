class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // vector<int> ans(temperatures.size(), 0);
        // stack<int> s;
        // // s.push(temperatures[temperatures.size() - 1]);
        // for (int i = temperatures.size() - 1; i >= 0; i--) {
        //     while (!s.empty() && temperatures[s.top()] <= temperatures[i]) {
        //         s.pop();
        //     }
        //     if (!s.empty()) {
        //         ans[i] = s.top() - i;
        //     }
        //     s.push(i);
        // }
        // return ans;
        vector<int> ans(temperatures.size(), 0);
        stack<int> s;
        // s.push(temperatures[temperatures.size() - 1]);
        for (int i = temperatures.size() - 1; i >= 0; i--) {
            if (s.empty()) {

                s.push(i);
            } else {
                cout << s.top() << " ";
                if (temperatures[s.top()] > temperatures[i]) {
                    s.push(i);
                    ans[i] = 1;

                } else {
                    while (!s.empty() &&
                           temperatures[s.top()] <= temperatures[i]) {
                        s.pop();
                    }
                    if (!s.empty()) {
                        ans[i] = s.top() - i;
                    }
                    s.push(i);
                }
            }
        }
        return ans;
    }
};