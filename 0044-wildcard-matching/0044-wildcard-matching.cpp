class Solution {
public:
    bool isAllStars(string &S1, int i) {
        // Check if the pattern up to index i contains only '*'
        for (int j = 1; j <= i; j++) {
            if (S1[j - 1] != '*')
                return false;
        }
        return true;
    }

    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // Base case: Both s and p are empty
        dp[0][0] = true;

        // Initialize first row for cases where s is empty
        for (int j = 1; j <= n; j++) {
            dp[0][j] = isAllStars(p, j);  // Only '*' can match an empty string
        }

        // Fill the dp table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else {
                    dp[i][j] = (s[i - 1] == p[j - 1]) && dp[i - 1][j - 1];
                }
            }
        }

        return dp[m][n];
    }
};
