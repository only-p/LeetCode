class Solution {
public:
    int characterReplacement(string s, int k) {
        int low =0,ans=0;
        int maxFrq=0;
        unordered_map<char,int>m;
        for(int high =0;high<s.size();high++){
            m[s[high]]++;
            maxFrq = max(maxFrq,m[s[high]]);
            while(high-low+1-maxFrq>k){
                if(m[s[low]]==1)m.erase(s[low]);
                else m[s[low]]--;
               low++;
                
            }
            ans = max(ans,high-low+1);
        }
        return ans;
    }
};