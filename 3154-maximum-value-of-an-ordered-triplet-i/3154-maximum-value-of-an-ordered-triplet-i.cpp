class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int maxi = 0;
        vector<int> suffixGreater(nums.size(),0);
        for(int i=nums.size()-1; i>=0; i--){
            maxi = max(maxi, nums[i]);
            suffixGreater[i] = maxi;
        }
        maxi = nums[0];
        long long ans = 0;
        for(int i=1; i<nums.size()-1; i++){
            ans = max(ans, (maxi - nums[i])*1LL*suffixGreater[i+1]);
            maxi = max(maxi,nums[i]);
        }
        return ans;
    }
};