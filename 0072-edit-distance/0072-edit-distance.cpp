class Solution {
public:
    int rec(int i, int j, string word1, string word2,vector<vector<int>> &dp){
        if(j<0 || i<0)  return max(i+1,j+1);
        if(dp[i][j] != -1)  return dp[i][j];
        
        if(word1[i] == word2[j]){
            return dp[i][j] = rec(i-1,j-1,word1,word2, dp);
        }
        else{
            int insert = 1 + rec(i-1,j,word1,word2, dp);
            int del = min(insert, 1 + rec(i,j-1,word1,word2, dp));
            int replace = min(del,1 + rec(i-1,j-1,word1,word2, dp));
            return dp[i][j] = replace;
        }
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
        return rec(word1.size()-1, word2.size()-1,word1, word2, dp);
    }
};