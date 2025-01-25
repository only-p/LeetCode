class Solution {
    public boolean check(int[] nums) {
        int cnt = 0;
        int n = nums.length;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1])
                cnt++;
        }
        if (nums[n - 1] > nums[0])
            cnt++;
        return cnt > 1 ? false : true;
    }
}