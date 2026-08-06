class Solution {
public:
    int smallestNumber(int n, int t) {
        int cnt = n;
        while(true){
            int mul = 1;
            int m = cnt;
            while(m){
                mul*=m%10;
                m/=10;
            }
            if(mul%t==0){
                return cnt;
            }
            cnt++;
        }
        return 0;
        
    }
};