class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int l=0,r;
        int maxi = 1;
        for(r=1; r<nums.size(); r++){
            if(nums[r] <= nums[r-1]){
                l = r;
            }
            maxi = max(maxi, r-l+1);
        }
        l=0;
        for(r=1; r<nums.size(); r++){
            if(nums[r] >= nums[r-1]){
                l = r;
            }
            maxi = max(maxi, r-l+1);
        }
        return maxi;
    }
};