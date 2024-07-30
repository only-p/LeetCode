class Solution {
    int getSqure(int n) {
        int ans = 0;
        while (n) {
            ans += ((n % 10) * (n % 10));
            n /= 10;
        }
        return ans;
    }

public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        slow = getSqure(n);
        fast = getSqure(getSqure(n));
        while (slow != fast) {
            slow = getSqure(slow);
            fast = getSqure(getSqure(fast));
        }
        return slow==1;
    }
};