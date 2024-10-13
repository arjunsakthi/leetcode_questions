class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<vector<vector<int>>> dp; // Dynamic memory allocation for dp

    int rec(char last, int idx, string &s, unordered_map<string, int> &mpp, int points) {
        if (idx < 0) {
            return points > 0 ? 1 : 0;  
        }
        
        int lastIndex;
        if (last == 'F') lastIndex = 0;
        else if (last == 'W') lastIndex = 1;
        else if (last == 'E') lastIndex = 2;
        else lastIndex = 3; 
        
        if (dp[idx][lastIndex][points + 10000] != -1) return dp[idx][lastIndex][points + 10000];

        int maxi = 0;
        char st = s[idx];

        if (last != 'F') {
            string temp = 'F' + string(1, st);  
            maxi = (maxi + rec('F', idx - 1, s, mpp, points + mpp[temp]) % MOD) % MOD;
        }
        
        if (last != 'W') {
            string temp = 'W' + string(1, st);  
            maxi = (maxi + rec('W', idx - 1, s, mpp, points + mpp[temp]) % MOD) % MOD;
        }
        
        if (last != 'E') {
            string temp = 'E' + string(1, st);  
            maxi = (maxi + rec('E', idx - 1, s, mpp, points + mpp[temp]) % MOD) % MOD;
        }

        return dp[idx][lastIndex][points + 10000] = maxi % MOD;
    }

    int countWinningSequences(string s) {
        unordered_map<string, int> mpp = {
            {"FF", 0}, {"FW", -1}, {"FE", 1},
            {"WF", 1}, {"WW", 0}, {"WE", -1},
            {"EF", -1}, {"EW", 1}, {"EE", 0}
        };

        int n = s.size();
        dp = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(4, vector<int>(20005, -1))); // Initialize dp on the heap
        int points = 0;

        return rec('O', s.size() - 1, s, mpp, points);
    }
};
