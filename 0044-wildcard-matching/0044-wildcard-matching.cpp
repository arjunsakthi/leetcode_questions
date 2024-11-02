class Solution {
public:
    bool isAllStars(string &S1, int i) {
    // S1 is taken in 1-based indexing
    for (int j = 1; j <= i; j++) {
        if (S1[j - 1] != '*')
            return false;
    }
    return true;
}
    bool rec(int i, int j, string s, string p){
        if(i<0 && j<0)  return true;
        else if(i <0 || j<0)    return false;

        if(p[j] == '?'){
            return rec(i-1,j-1,s,p);
        }
        else if(p[j] == '*'){

                return rec(i-1,j,s,p) || rec(i,j-1,s,p) || rec(i-1,j-1,s,p);
        }
        else{
            if(s[i] != p[j])    return false;
            else    return rec(i-1,j-1,s,p);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        // return rec(s.size()-1, p.size()-1, s, p);
        vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1,0));
        dp[0][0] = true;
        for (int i = 1; i <= p.size(); i++) {
            dp[0][i] = isAllStars(p, i);
        }
        for(int i=1; i<=s.size(); i++){
            for(int j=1; j<=p.size(); j++){
                if(p[j-1] == '?'){
            dp[i][j] = dp[i-1][j-1];
        }
        else if(p[j-1] == '*'){

                dp[i][j] = dp[i-1][j] || dp[i][j-1];
        }
        else{
            dp[i][j] = (s[i - 1] == p[j - 1]) && dp[i - 1][j - 1];
        }
            }
        }
        return dp[s.size()][p.size()];
    }
};