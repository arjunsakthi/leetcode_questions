class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<double>> dp(s.size(),vector<double>(t.size(),0));
        for(int i=0; i<s.size(); i++){
            for(int j=0; j<t.size(); j++){
                if(i>0) dp[i][j] += dp[i-1][j];
                if(s[i]==t[j]){
                    if(j == 0)  dp[i][j] += 1;
                    else if(i>0){
                        dp[i][j] += dp[i-1][j-1];
                    }
                }
            }
        }
        return (int)dp[s.size()-1][t.size()-1];

    }
};