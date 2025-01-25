class Solution {
    public boolean check(int[] nums) {
        int cnt=0;
        int n = nums.length;
        for(int i=0;i<n;i++){
            cnt =0;
            for(int j=0;j<n;j++){
                // cout<<(i+j)%n<<"  "<<(i+j+1)%n ;
                if(nums[(i+j)%n]>nums[(i+j+1)%n])cnt++;
            }
            if(cnt<2)return true;

        }
        return false;
    }
}