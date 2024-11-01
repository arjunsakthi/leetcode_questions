#define MOD 1000000007

class Solution {
public:
    long long rec(int i, int seq1, int seq2, vector<int>& nums,vector<vector<vector<long long>>> &dp){
        if(i == -1){
            if(seq1 == seq2)    return 1;
            else return 0;
        }
        if(dp[i][seq1][seq2] != -1) return dp[i][seq1][seq2];
        long long ch1 = rec(i-1, gcd(seq1,nums[i]),seq2,nums,dp);
        long long ch2 = rec(i-1, seq1, gcd(seq2,nums[i]),nums,dp);
        long long ch3 = rec(i-1, seq1, seq2,nums,dp);

        return dp[i][seq1][seq2] = (ch1%MOD+ch2%MOD+ch3%MOD)%MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        vector<vector<vector<long long>>> dp(nums.size(), vector<vector<long long>>(201,vector<long long>(201,-1))); 
        return (int)rec(nums.size()-1,0,0,nums,dp)-1;
    }
};