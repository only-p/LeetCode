class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int ans = 0;
        unordered_map<char, int> frq;
        for (int end = 0; end < s.size(); end++) {
            if(frq.find(s[end])!=frq.end()){
                start = max(start,frq[s[end]]+1);
            }
            frq[s[end]] = end;
            ans = max(ans,end-start+1);
        }
        return ans;
    }
};