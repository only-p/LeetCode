class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start=0;
        int cnt=0;
        int maxLen=0;
        for(int end =0 ;end<nums.size();end++){
            if(nums[end]==0)cnt++;
            while(cnt>k){
                if(nums[start]==0)cnt--;
                start++;
            }
            maxLen = max(maxLen,end-start+1);


        }
        return maxLen;
        
    }
};