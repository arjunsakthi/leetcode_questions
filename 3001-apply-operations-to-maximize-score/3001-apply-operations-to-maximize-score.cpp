class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        vector<int> primeCount(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            primeCount[i] = countPrimeFactors(nums[i]);
        }

        // counting window for each ele
        vector<int> leftEnd(nums.size()), rightEnd(nums.size());
        stack<int> st; // index

        for (int i = 0; i < nums.size(); i++) {
            int ele = primeCount[i];
            while (!st.empty() && primeCount[st.top()] < ele)
                st.pop();

            if (st.empty()) {
                leftEnd[i] = -1;
            } else {
                leftEnd[i] = st.top();
            }
            st.push(i);
        }
        while (!st.empty())
            st.pop();

        for (int i = nums.size() - 1; i >= 0; i--) {
            int ele = primeCount[i];
            while (!st.empty() && primeCount[st.top()] <= ele)
                st.pop();

            if (st.empty()) {
                rightEnd[i] = nums.size();
            } else {
                rightEnd[i] = st.top();
            }
            st.push(i);
        }
        vector<long long> count(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            count[i] = (i - leftEnd[i]) * 1LL * (rightEnd[i] - i);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>> qu;
        for (int i = 0; i < nums.size(); i++) {
            qu.push({nums[i], i});
        }

        // main
        int ans = 1;
        int mod = 1000000007;
        while (k > 0 && !qu.empty()) {
            pair<int, int> top = qu.top();
            qu.pop();
            ans =
                (ans * 1LL * power(top.first, (int)min(k*1LL, count[top.second]), mod))%
                mod;
            k -= min(k*1LL, count[top.second]);
        }
        return ans;
    }

private:
    int power(int base, int n, int mod) {
        int ans = 1;
        while (n > 0) {
            if (n & 1)
                ans = (ans * 1LL * base) % mod;
            base = (base * 1LL * base) % mod;
            n /= 2;
        }
        return ans % mod;
    }

    int countPrimeFactors(int n) {
        int c = 0;
        for (int i = 2; i * i < n; i++) {
            if (n % i == 0) {
                c++;
                while (n > 1 && n % i == 0) {
                    n = n / i;
                }
            }
        }
        if (n != 1)
            c++;
        return c;
    }
};