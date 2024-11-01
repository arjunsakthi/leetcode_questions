class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        // Step 1: Build the DP array for LCS
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // Step 2: Build the shortest common supersequence using LCS
        string ans = "";
        int i = n, j = m;

        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                ans.push_back(str1[i - 1]);
                i--;
                j--;
            } else if (dp[i - 1][j] >= dp[i][j - 1]) {
                ans.push_back(str1[i - 1]);
                i--;
            } else {
                ans.push_back(str2[j - 1]);
                j--;
            }
        }

        // Add remaining characters from str1 and str2
        while (i > 0) {
            ans.push_back(str1[i - 1]);
            i--;
        }
        while (j > 0) {
            ans.push_back(str2[j - 1]);
            j--;
        }

        // The answer is built in reverse order, so reverse it before returning
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
