class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int ans = n + 1;
        int pan = n + 1;
        vector<int> open(n+1, 0), close(n+1, 0);
        if (customers[0] == 'N')
            open[0] = 1;

        for (int i = 1; i < n; i++) {
            if (customers[i] == 'N')
                open[i] = 1 + open[i - 1];
            else
                open[i] = open[i - 1];
        }
        if (customers[n - 1] == 'Y')
            close[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (customers[i] == 'Y')
                close[i] = 1 + close[i + 1];
            else
                close[i] = close[i + 1];
        }
        for (int i = 0; i <= n; i++) {
            int p = n + 5;
            if (i == 0)
                p = close[0];
            else {
                p = close[i] + open[i - 1];
            }
            if (p < pan) {
                pan = p;
                ans = i;
            }
        }
        return ans;
    }
};