class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen=0;
        int start=0;
        unordered_map<char,int>frq;
        for(int end =0;end<s.size();end++){
            char r = s[end];
            cout<<r;
            if(frq.find(r)!=frq.end()){
                start = max(start,frq[r]+1);
            }
            frq[r]=end;
            maxLen = max(maxLen,end-start+1);
        }
        return maxLen;
    }
};