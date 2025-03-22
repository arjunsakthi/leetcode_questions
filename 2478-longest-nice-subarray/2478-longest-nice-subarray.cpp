class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int maxi = 1;
        int low=0,high=0;
        int sum=0;
        int exor=0;
        while(high <nums.size()){
            if(sum == exor){
                maxi = max(high - low,maxi);
                exor ^= nums[high];
                sum += nums[high];
                high++;
            }
            else{
                exor ^= nums[low];
                sum -= nums[low];
                low++;
            }
        } 
        if(sum == exor)maxi = max(high - low,maxi);
        return maxi;
    }
};