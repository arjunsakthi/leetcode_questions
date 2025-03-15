class Solution {
public:
    bool rec(string &s, string &p, int i, int j,vector<vector<int>> &dp){
        if(j<0 && i<0)  return true;
        if(j<0) return false;
          
        if(i<0){
            while(j>=0 && p[j]=='*'){
                j--;
            }
            return j==-1?true:false;
        }
      if(dp[i][j] != -1)return dp[i][j];
        if(s[i]==p[j] || p[j] == '?'){
            return dp[i][j] = rec(s,p,i-1,j-1,dp);
        }
        else{
            if(p[j] == '*'){
                return dp[i][j] = (rec(s,p,i-1,j,dp)||rec(s,p,i,j-1,dp));
            }
            else{
                return dp[i][j] = false;
            }
        }
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size(),vector<int>(p.size(),-1));
        return rec(s,p,s.size()-1,p.size()-1,dp);
    }
};