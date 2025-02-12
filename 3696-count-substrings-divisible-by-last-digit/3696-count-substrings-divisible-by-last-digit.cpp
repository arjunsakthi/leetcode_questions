class Solution {
public:
    long long countSubstrings(string s) {
        vector<vector<vector<int>>> dp(
            s.size() + 1, vector<vector<int>>(10, vector<int>(10, 0)));
        // index, lastDigit, remainder
        // 1 based indexing
        long long ans = 0;
        for (int i = 1; i <= s.size(); i++) {
            int digit = s[i - 1] - '0';
            for (int lastD = 1; lastD < 10; lastD++) {
                for (int rem = 0; rem < lastD; rem++) {
                    int newRem = (rem * 10 + digit) % lastD;
                    dp[i][lastD][newRem] += dp[i - 1][lastD][rem];
                }
                dp[i][lastD][(digit) % lastD]++;
            }
            ans += dp[i][digit][0];
        }

        return ans;
    }
};