class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto &i : roads) {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }

        vector<long long> distance(n, LLONG_MAX);
        vector<int> count(n, 0);
        int MOD = 1e9 + 7;

        distance[0] = 0;
        count[0] = 1;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, 0}); // (distance, node)

        while (!pq.empty()) {
            auto [dis, node] = pq.top();
            pq.pop();

            if (dis > distance[node]) continue; // Skip outdated entries

            for (auto &[neighbor, weight] : adj[node]) {
                long long newDist = distance[node] + weight;

                if (newDist < distance[neighbor]) {
                    distance[neighbor] = newDist;
                    count[neighbor] = count[node];  // Reset path count
                    pq.push({newDist, neighbor});
                } else if (newDist == distance[neighbor]) {
                    count[neighbor] = (count[neighbor] + count[node]) % MOD;
                }
            }
        }

        return count[n - 1];
    }
};
