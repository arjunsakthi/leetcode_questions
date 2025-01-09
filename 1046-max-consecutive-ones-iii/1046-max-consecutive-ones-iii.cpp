class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count = 0;
        int zeroC = 0;
        int maxi = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0)    zeroC++;
            count++;
            if(zeroC <= k){
                maxi = max(maxi, count);
            }
            else{
                if(nums[i-count + 1] == 0)   zeroC--;
                count--;
            }
        }
        return maxi;
    }
};