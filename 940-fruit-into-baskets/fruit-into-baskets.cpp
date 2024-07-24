class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxLen = 0;
        int start =0;
        int cnt=0;
        unordered_map<int,int>freq;
        for(int end =0;end <fruits.size();end++){
            freq[fruits[end]]+=1;
            if(freq[fruits[end]]==1)cnt++;
            while(cnt>2){
                if(freq[fruits[start]]==1)cnt--;
                freq[fruits[start]]--;
                start++;
            }
            maxLen = max(maxLen,end-start+1);
        }
        return maxLen;
    }
};