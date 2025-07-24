class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        long long ans = 0;
        int sign = 1;

        // 1. Skip leading whitespaces
        while (i < n && s[i] == ' ')
            i++;

        // 2. Handle optional sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Process digits
        while (i < n && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');

            // 4. Clamp if overflow
            if (sign == 1 && ans > INT32_MAX)
                return INT32_MAX;
            if (sign == -1 && -ans < INT32_MIN)
                return INT32_MIN;

            i++;
        }

        return int(sign * ans);
    }
};