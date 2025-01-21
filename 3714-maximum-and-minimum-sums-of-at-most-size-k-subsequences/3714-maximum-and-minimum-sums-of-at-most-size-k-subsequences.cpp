class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int exponential(int a, int b) {
        int res = 1;
        while (b > 0) {
            if (b % 2) res = (res * 1LL * a) % MOD;
            a = (a * 1LL * a) % MOD;
            b >>= 1;
        }
        return res % MOD;
    }

    void factorial(vector<vector<int>>& fact) {
        if (fact.empty()) return;
        fact[0][0] = 1;
        for (int i = 1; i < fact.size(); i++) {
            fact[i][0] = (fact[i - 1][0] * 1LL * i) % MOD;
        }
        fact[fact.size() - 1][1] = exponential(fact[fact.size() - 1][0], MOD - 2);
        for (int i = fact.size() - 2; i >= 0; i--) {
            fact[i][1] = (fact[i + 1][1] * 1LL * (i + 1)) % MOD;
        }
    }

    int combination(int n, int k, const vector<vector<int>>& fact) {
        if (k > n || k < 0) return 0;
        return (((fact[n][0] * 1LL * fact[k][1]) % MOD) * fact[n - k][1]) % MOD;
    }

    int minMaxSums(vector<int>& nums, int k) {
        if (nums.empty() || k <= 0) return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> factInvFact(n, vector<int>(2, 1));
        factorial(factInvFact);

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                int mini = combination(n - i - 1, j - 1, factInvFact)*1LL*nums[i]%MOD;
                int maxi = combination(i, j - 1, factInvFact)*1LL*nums[i]%MOD;
                res = (res + mini +0LL+ maxi) % MOD;
            }
        }
        return res;
    }
};
