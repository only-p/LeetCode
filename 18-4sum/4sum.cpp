class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> ans;
        if (nums.size() < 4)
            return ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size() - 2; j++) {
                long long newtarget =
                    (long long)target - (long long)nums[i] - (long long)nums[j];
                int left = j + 1;
                int right = nums.size() - 1;

                while (left < right) {
                    int s = nums[left] + nums[right];
                    if (s == newtarget) {
                        ans.push_back(
                            {nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        while (left < right && nums[left] == nums[left - 1]) {
                            left++;
                        }
                        while (left < right && nums[right] == nums[right + 1]) {
                            right--;
                        }
                    } else if (s < newtarget) {
                        left++;
                    } else {
                        right--;
                    }
                }
                while (j + 1 < nums.size() && nums[j] == nums[j + 1])
                    j++;
            }
            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
                i++;
        }
        return ans;
    }
};