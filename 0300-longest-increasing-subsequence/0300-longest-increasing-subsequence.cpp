class Solution {
public: 

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1,0));
        // return lic(0,-1e5,nums,vector<int> dp);
        for(int i=1 ;i<=nums.size(); i++){
            for(int j=i; j<=nums.size(); j++){ // j saying the next greater element and nums.size() no element taken till ith index
                int k = 0;
                if(j == nums.size() || nums[i-1] < nums[j]){
                    k = 1+dp[i-1][i-1];
                }
                dp[i][j] = max(k,dp[i-1][j]);
            }
        }
        return dp[nums.size()][nums.size()];
    }
};