class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size(),-1);
        for(int i=0; i<nums.size();i++){
            if(nums[i] == 2){
                ans[i] = -1;
                continue;
            }
            int j;
            for(j=0;j<32;j++){
                
                if((1<<j)&nums[i]) continue;
                else{
                    break;
                }
            }
                   // Binary: 1011
            ans[i] =nums[i] & (~(1 << (j-1)));   
        }
        return ans;
    }
};