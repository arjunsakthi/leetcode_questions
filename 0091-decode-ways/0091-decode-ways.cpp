class Solution {
public:

    int f(int k, string s,vector<int> dp){
        if(k > s.size())    return 1;
        if(s[k-1] == 0)   return 0;
        if(dp[k] != -1) return dp[k];
        int take2 = 0, take1 = 0;
        if(k <= s.size()-1 && s[k-1] != '0' &&(( s[k-1] < '3' && s[k] < '7') || (s[k-1] < '2'))){
            take2 = f(k+2,s,dp);
        }
        if(s[k-1] != '0')
            take1 = f(k+1,s,dp);
        return dp[k] = take1+take2;
    }

    int numDecodings(string s) {
        vector<int> dp(s.size()+2,0);
        dp[s.size()+1] = 1;
        for(int k=s.size(); k>=1; k--){
            int take2 = 0, take1 = 0;
        if(k <= s.size()-1 && s[k-1] != '0' &&(( s[k-1] < '3' && s[k] < '7') || (s[k-1] < '2'))){
            take2 = dp[k+2];
        }
        if(s[k-1] != '0')
            take1 = dp[k+1];
        dp[k] = take1 + take2;
        }
        return dp[1];
    }
};