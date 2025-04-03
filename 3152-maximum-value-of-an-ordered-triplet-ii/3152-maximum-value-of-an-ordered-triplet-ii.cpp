class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
               int maxi = 0;
        long long ans=0;
        int imax = 0;
        int dmax = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            ans = max(ans, dmax*1LL*nums[i]);
            dmax = max(dmax, imax - nums[i]);
            imax = max(imax, nums[i]);
        }
        return ans;
    }
};