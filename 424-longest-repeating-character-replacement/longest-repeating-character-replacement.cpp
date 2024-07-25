class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen=0;
        int maxFrq=0;
        int start =0;
        int cnt=0;
        unordered_map<char,int>frq;

        for(int end=0;end<s.size();end++){

            frq[s[end]] +=1;
            maxFrq = max(maxFrq,frq[s[end]]);

            if(end-start+1-maxFrq>k){
                frq[s[start]]--;
                start++;
            }
            maxLen = max(maxLen,end-start+1);
        }
        return maxLen;
        
    }
};