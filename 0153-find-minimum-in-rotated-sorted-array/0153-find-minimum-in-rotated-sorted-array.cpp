class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int ans = nums[0];
        int target = INT_MIN;
        int high = nums.size()-1;
        while (low <= high) {
            int mid = (low+high)/2;
            ans = min(ans,nums[mid]);
            if (nums[low] <= nums[mid]) {
                ans = min(ans,nums[low]);
                if((target < nums[mid]) && (target >= nums[low])) {
                    high = mid-1;
                }
                else {
                    low = mid+1;
                }
            }
            else {
                if ((target > nums[mid]) && (target <= nums[high])) {
                    low = mid+1;
                }
                else {
                    high = mid-1;
                }
            }
        }
        return ans;
    }
};