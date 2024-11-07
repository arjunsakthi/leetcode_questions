class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        int lastIndex = 0;
        vector<int> hash(n,1);
        sort(nums.begin(),nums.end());
        int maxi = 1;
        for(int i=0; i<n; i++){
            hash[i] = i;
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j] == 0 && dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                    hash[i]=j;
                }
            }
            if(maxi < dp[i]){
                maxi = dp[i];
                lastIndex=i;
            }
        }
        vector<int> ans;
        while(hash[lastIndex] != lastIndex){
            ans.push_back(nums[lastIndex]);
            lastIndex = hash[lastIndex];
        }
        ans.push_back(nums[lastIndex]);
        return ans;
    }
};