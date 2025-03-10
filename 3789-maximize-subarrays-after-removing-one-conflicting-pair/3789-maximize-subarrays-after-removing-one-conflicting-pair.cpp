class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        int m = conflictingPairs.size();
        vector<vector<pair<int, int>>> start(n + 1);
        for (int i = 0; i < m; i++) {
            start[min(conflictingPairs[i][0],conflictingPairs[i][1])].push_back(
                {max(conflictingPairs[i][0],conflictingPairs[i][1]), i});
        }
        set<pair<int, int>> rightConf;
        vector<int> freq(n + 1, 0);
        long long base = 0;
        vector<long long> improvement(m, 0);
        for (int i = n; i > 0; i--) {
            for (auto [a,s] : start[i]) {
                rightConf.insert({a,s});
                freq[a]++;
            }
            if (rightConf.empty()) {
                base += n + 1 - i;
            } else {
                int r = rightConf.begin()->first;
                int ind = rightConf.begin()->second;
                base += r - i;
                if (freq[r] == 1) {
                    auto second = rightConf.upper_bound({r, m});
                    improvement[ind] +=
                        ((second != rightConf.end()) ? second->first : n + 1) -
                        r;
                }
            }
        }
        return base + *max_element(improvement.begin(), improvement.end());
    }
};