class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int count = 0;
        int maxc = 0;
        for(int i=0; i<nums.size(); i++){
            if(maxi == nums[i]){
                count++;
            }
            else if(count > 0){
                maxc = max(maxc,count);
                count=0;
            }
        }
        maxc = max(maxc,count);
        return maxc;
    }
};