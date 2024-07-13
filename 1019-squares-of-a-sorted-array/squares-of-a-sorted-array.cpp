class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans(nums.size());
        int left=0,right = nums.size()-1;
        int currentIdx = nums.size()-1;
        while(left<=right){
            int ls = nums[left]*nums[left];
            int rs = nums[right]*nums[right];
            if(ls>rs){
                ans[currentIdx--]=ls;
                left++;
            }else{
                ans[currentIdx--] = rs;
                right--;
            }
        }
        return ans;
        
    }
};