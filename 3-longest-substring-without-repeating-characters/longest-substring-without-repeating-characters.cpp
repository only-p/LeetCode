class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int ans = 0;
        unordered_set<char> frq;
        for (int end = 0; end < s.size(); end++) {
            while(frq.find(s[end])!=frq.end()){
                frq.erase(s[start]);
                start++;
            }
            frq.insert(s[end]);
            ans = max(ans,end-start+1);
            
        }
        return ans;
    }
};