class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,ans=0;
        int cnt=0;
        unordered_map<char,int>m;
        while(j<s.size()){
            if(m[s[j]]==1){
                while(i<=j && m[s[i]]!=m[s[j]] ){
                    m[s[i]]=0;
                    cnt--;
                    i++;
                }
                
                m[s[i]]=0;
                i++;
                cnt--;

            }else{
                m[s[j]]=1;
                j++;
                cnt++;
                ans=max(ans,cnt);
            }
        }
        return ans;
        
    }
};