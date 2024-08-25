class Solution {
public:
    long long f(int n, int k, int target, vector<vector<long long>> &dp){
        if(target < 0)  return 0;
        if(n == 0){
            if(target == 0) return 1;
            else return 0;
        }
        long long sum = 0;
        if (dp[n][target] != -1) return dp[n][target];
        for(int i=1; i<=k; i++){
            sum = (sum +  f(n-1, k, target - i,dp))%1000000007;
        }
        return dp[n][target] = sum;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long>> dp(n+1,vector<long long>(target+1,-1));
        return f(n,k,target,dp);
    }
};