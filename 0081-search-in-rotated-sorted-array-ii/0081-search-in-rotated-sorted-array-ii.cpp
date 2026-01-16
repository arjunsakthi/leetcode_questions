class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while (low <= high) {
            while ((high > 0) && (nums[high] == nums[high-1])) high--;
            while ((low < nums.size()-1) && (nums[low] == nums[low+1])) low++;
            int mid = (low+high)/2;
            if(target == nums[mid]) {
                return true;
            }
            else if (nums[low] <= nums[mid]) {
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
        return false;
    }
};