class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z = 0;
        int t = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == 0 && i != z) {
                swap(nums[i], nums[z]);

                z++;
                i--;
            } else if (nums[i] == 2 && i != t) {
                swap(nums[i], nums[t]);
                t--;
                i--;
            }
            if (i >= t)
                break;
        }
    }
};