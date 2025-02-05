class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int l=0;
        int r=1;
        int maxi = nums[0];
        int sum = nums[0];
        for( r=1; r<nums.size(); r++){
            if(nums[r] <= nums[r-1]){
                l = r;
                sum = nums[r];
            }
            else{
                sum += nums[r];
            }
            maxi = max(sum, maxi);
        }
        return maxi;
    }
};