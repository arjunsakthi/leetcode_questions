class Solution {
public:
    bool canPartition(vector<int>& nums) {
         int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2)   return false;
        int half = sum/2;
        bitset<20001> b(1);
        for(auto i:nums){
            b |= (b<<i);
        }
        return b[half];


        // vector<vector<bool>> dp(nums.size(),vector<bool>(half+1,0));
        // for(int i=0; i<nums.size(); i++)    dp[i][0] = 1;
        // if(nums[0] <= half)dp[0][nums[0]]=1;
        // for(int i=1; i<nums.size(); i++){
        //     for(int j=0; j<=half; j++){
        //          dp[i][j] = dp[i-1][j] ;
        //         if(j - nums[i]>=0){
        //             dp[i][j] = dp[i][j] |  dp[i-1][j-nums[i]];
        //         }
        //     }
        // }
        return 1;
    }
};