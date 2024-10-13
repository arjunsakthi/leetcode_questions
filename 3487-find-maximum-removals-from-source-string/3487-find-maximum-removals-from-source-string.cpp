class Solution {
public:
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        vector<int> targetBool(3001,0);
        for(int i=0; i<targetIndices.size(); i++){
            targetBool[targetIndices[i]] = 1;
        }
        vector<vector<int>> dp(source.size()+1,vector<int>(pattern.size()+1,-2));
        // return rec(source.size()-1,pattern.size()-1,targetBool,source,pattern,dp);
        int offset = 1;
        dp[offset - 1][offset -1] = 0;
        for(int i=0 ;i<source.size();i++){
            dp[i+offset][0] =  0;
        }
        for(int i=0 ;i<source.size();i++){
            if(targetBool[i])   dp[i+offset][0] +=  1;
            dp[i+offset][0] += dp[i+offset-1][0];
        }
        for(int i=0; i<source.size(); i++){
            for(int j=0; j<pattern.size();j++){
                dp[i+ offset][j+ offset] = -1;
                if(source[i] == pattern[j]) dp[i + offset][j + offset] = dp[i-1 + offset][j-1 + offset];
                if(dp[i-1+ offset][j+ offset] != -1)
                    dp[i+ offset][j+ offset] = max(dp[i+ offset][j+ offset], dp[i-1+ offset][j+ offset]+targetBool[i]);
            }
        }
        return dp[source.size()][pattern.size()];
    }

private:
//     int rec(int i, int j, vector<int> targetBool, string source, string pattern,vector<vector<int>> &dp) {
//         if(i<j) return -1;
//     if(i < 0){
//         if(j < 0) return 0;
//         else return -1;
//     }
//     if(j<0) return rec(i-1,j,targetBool,source,pattern,dp)+targetBool[i];
//     if(j>=0 && dp[i][j] != -2)  return dp[i][j];
//     int take=-1,notTake=-1;
//     if(j >= 0 && source[i] == pattern[j]){
//         take = rec(i-1,j-1,targetBool,source,pattern,dp);
//     }
//     notTake=rec(i-1,j,targetBool,source,pattern,dp);
//     if(notTake != -1){
//         notTake += targetBool[i];
//     } 
//     return dp[i][j] = max(take,notTake);
// }
};
