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
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,0));
        for(int i=0; i<=word1.size(); i++){
            dp[i][0] = i;
        }
        for(int j=0; j<=word2.size(); j++){
            dp[0][j] = j;
        }
        // return rec(word1.size()-1, word2.size()-1,word1, word2, dp);
        if(word1.size() == 0)   return word2.size();
        if(word2.size() == 0)   return word1.size();
        for(int i=1; i<=word1.size(); i++){
            for(int j=1; j<= word2.size(); j++){
                if(word1[i-1] == word2[j-1]){
            dp[i][j] = dp[i-1][j-1];
        }
        else{
            int insert = 1 + dp[i][j-1];
            int del = min(insert, 1 +dp[i-1][j]);
            int replace = min(del,1 + dp[i-1][j-1]);
            dp[i][j] = replace;
        }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};