class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int j = 0; j < nums.size(); j++) {
             if (j != 0 && nums[j] == nums[j - 1])
                    continue;
            int num0 = nums[j];
            for (int i = j+1; i < nums.size(); i++) {
                if (i != (j+1) && nums[i] == nums[i - 1])
                    continue;
                int num1 = nums[i];
                long long req = target - (num1 +0LL+ num0);
                int low = i + 1;
                int high = nums.size() - 1;
                while (low < high) {
                    if (nums[low] +0LL+ nums[high] == req) {
                        ans.push_back({num0,num1, nums[low], nums[high]});
                        high--;
                        low++;
                    } else if (nums[low] + nums[high] < req) {
                        low++;

                    } else {
                        high--;
                    }
                    while (low < high && low != i+1 && nums[low] == nums[low - 1])
                        low++;
                    while (low < high && high != nums.size() - 1 &&
                           nums[high] == nums[high + 1])
                        high--;
                }
            }
        }

        return ans;
    }
};