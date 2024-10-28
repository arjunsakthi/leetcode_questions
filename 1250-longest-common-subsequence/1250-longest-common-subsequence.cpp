class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(),0));
        for(int i=0; i<text1.size(); i++){
            for(int j=0; j<text2.size(); j++){
                int take=0, nottake = 0;
                if(text1[i] == text2[j]){
                    if(i>0 && j>0){
                        take += dp[i-1][j-1];
                    }
                    take += 1;
                }
                else{
                    if(i>0) nottake += dp[i-1][j];
                    if(j>0) nottake = max(nottake,dp[i][j-1]);
                }
                dp[i][j] = max(nottake, take);
            }
        }
        return dp[text1.size()-1][text2.size()-1];
    }
};