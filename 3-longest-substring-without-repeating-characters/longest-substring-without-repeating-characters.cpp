class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low=0,ans=0;
        unordered_map<char,int>m;
        for(int high=0;high<s.size();high++){
            m[s[high]]++;
            while(m[s[high]]>1){
                if(m[s[low]]==1)m.erase(s[low]);
                else m[s[low]]--;
                low++;
            }
            ans = max(ans,high-low+1);
        }
        return ans;
        
    }
};