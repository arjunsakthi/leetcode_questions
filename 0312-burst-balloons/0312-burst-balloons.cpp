class Solution {
public:
    int f(vector<int>& nums,int low, int high){
        if(low >= high) return 0;
        int mini = INT_MIN;
        for(int i=low;i<high; i++){
            int cost = nums[low-1]*nums[i]*nums[high] + f(nums,low,i)+f(nums,i+1,high);
            mini = max(mini, cost);
        }
        return mini;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        // return f(nums,1,nums.size()-1);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(),0));
        for(int low = nums.size()-2; low>0; low--){
            for(int high = low; high<nums.size(); high++){
                int mini = INT_MIN;
                for(int i=low;i<high; i++){
                    int cost = nums[low-1]*nums[i]*nums[high] + dp[low][i] + dp[i+1][high];
                    mini = max(mini, cost);
                }
                if(low == high)
                    dp[low][high] = 0;
                else
                    dp[low][high] = mini;
            }
        }
        return dp[1][nums.size()-1];
    }
};