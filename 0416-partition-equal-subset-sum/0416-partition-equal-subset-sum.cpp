class Solution {
public:
    bool f_rec(vector<int>& nums, double temp_sum, int n, double sum,vector<vector<double>>& dp){
        if(temp_sum > sum/2)    return false;
        if(temp_sum == sum/2)   return true;
        if(n == 0)  return (nums[0]+temp_sum == sum/2);
        if(dp[n][temp_sum] != -1)  return dp[n][temp_sum];
        int take = f_rec(nums, temp_sum + nums[n], n-1, sum, dp);
        int nottake = f_rec(nums, temp_sum,n-1,sum, dp);
        return dp[n][temp_sum] = take || nottake;
    }

    bool canPartition(vector<int>& nums) {
        double sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        double temp_sum = 0;
        vector<vector<double>> dp(nums.size()+1,vector<double>(sum+1,-1));
        bool k = f_rec(nums, temp_sum, nums.size()-1, sum, dp);
        cout << sum << temp_sum;
        return k;
    }
};