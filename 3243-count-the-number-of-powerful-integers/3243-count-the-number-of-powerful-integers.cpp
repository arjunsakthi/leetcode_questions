class Solution {
public:
    long long rec(string& nums, int n, int tight, int& limit, string& s,vector<vector<long long>> &dp) {
        if (nums.size() < s.size())
            return 0;
        if(n==0)    return 1;
        int upper = tight ? nums[nums.size() - n] - '0' : limit;
        if(dp[n][tight] != -1)  return dp[n][tight];
        long long ans = 0;
        if (n <= s.size()) {
            if (!tight)
                return 1;
            else if (upper > s[s.size() - n] - '0')
                return 1;
            else if (upper == s[s.size() - n] - '0') {
                ans = rec(nums, n - 1, tight, limit, s,dp);
            } else {
                return 0;
            }
        } else {
            for (int i = 0; i <= limit && i <= upper; i++) {
                ans += rec(nums, n - 1, (tight & (i == upper)), limit, s,dp);
            }
        }
        return dp[n][tight] = ans;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                  string s) {
                                    start--;
        string starts = to_string(start);
        string finishs = to_string(finish);
        if ((finishs.size() == s.size() && finishs < s) ||
            (finishs.size() < s.size())) {
            return 0;
        }
        vector<vector<long long>> dp(finishs.size() + 1, vector<long long>(limit + 1, -1));
        long long a = rec(finishs, finishs.size(), 1, limit, s, dp);
        dp.assign(dp.size(), vector<long long>(dp[0].size(), -1));
        long long b = rec(starts, starts.size(), 1, limit, s, dp);
        return  a-b;
               
    }
};