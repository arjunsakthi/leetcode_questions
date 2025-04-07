class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int maxInd = 0;
        vector<int> ans;
        sort(nums.begin(),nums.end());
       vector<int> dp(nums.size(),1), parent(nums.size(),0);
       dp[0] = 1;
       for(int i=0; i<nums.size(); i++){
            parent[i] = i;
       }
       for(int i=1;i<nums.size();i++){
        for(int j=0; j<i; j++){
            if((nums[i]%nums[j]==0 || nums[j]%nums[i] == 0) && 1+dp[j] > dp[i]){
                dp[i] = 1+dp[j];
                parent[i]=j;
            }
        }
       }
       int maxi = 0;
       for(int i=0; i<nums.size(); i++){
        if(dp[i] > maxi){
            maxInd = i;
            maxi = dp[i];
        }
       }
       ans.push_back(nums[maxInd]);
       while(maxInd != parent[maxInd]){
            maxInd = parent[maxInd];
            ans.push_back(nums[maxInd]);
       }
       return ans;

    }
};