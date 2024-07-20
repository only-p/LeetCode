class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; i++) {
            // if (i > 0 && nums[i] == nums[i - 1])
            //     continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {

                int currentSum = nums[i] + nums[left] + nums[right];

                if (currentSum == target) {

                    return target;
                }
                if (abs(target - currentSum) < abs(target - closest)) {
                    closest = currentSum;
                }
                if (currentSum > target) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        return closest;
    }
};