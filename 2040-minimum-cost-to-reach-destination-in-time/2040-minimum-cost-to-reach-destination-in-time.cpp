#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>

using namespace std;

struct Pair {
    int node;
    int time;
    Pair(int n, int t) : node(n), time(t) {}
};

class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();

        // Adjacency list: node -> list of {neighbor, time}
        vector<vector<Pair>> adj(n);
        createAdjacency(adj, edges);

        // dp[i][t] = min cost to reach node i at time t
        vector<vector<int>> dp(n, vector<int>(maxTime + 1, INT_MAX));
        dp[0][0] = passingFees[0];

        // Priority queue: {total_cost, time_used, node}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({passingFees[0], 0, 0});

        while (!pq.empty()) {
            auto [curCost, curTime, u] = pq.top();
            pq.pop();

            // If reached destination
            if (u == n - 1) return curCost;

            for (auto& nbr : adj[u]) {
                int v = nbr.node;
                int time = nbr.time;
                int newTime = curTime + time;
                int newCost = curCost + passingFees[v];

                if (newTime <= maxTime && newCost < dp[v][newTime]) {
                    dp[v][newTime] = newCost;
                    pq.push({newCost, newTime, v});
                }
            }
        }

        return -1;  // If destination not reachable within time
    }

private:
    void createAdjacency(vector<vector<Pair>>& adj, const vector<vector<int>>& edges) {
        for (const auto& e : edges) {
            int u = e[0], v = e[1], t = e[2];
            adj[u].emplace_back(v, t);
            adj[v].emplace_back(u, t);
        }
    }
};
