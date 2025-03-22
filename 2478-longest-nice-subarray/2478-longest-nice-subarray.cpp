class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int maxi = 1;
        int low=0,high=0;
        int usedBits = 0;
        while(high <nums.size()){
            while((usedBits & nums[high])!=0){
                usedBits ^= nums[low];
                low++;
            }
            usedBits ^= nums[high];
            maxi = max(maxi, high - low+1);
            high++;
        } 
        return maxi;
    }
};