class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> minCost(m, vector<int>(n, INT_MAX));
        deque<array<int, 2>> dque;
        dque.push_front({0, 0});
        minCost[0][0] = 0;

        vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!dque.empty()) {
            auto arr = dque.front();
            dque.pop_front();
            int r = arr[0];
            int c = arr[1];

            // Visit adjacent cells
            for (int i = 0; i < 4; i++) {
                int nr = r + direction[i][0];
                int nc = c + direction[i][1];
                int cost = (grid[r][c] != (i + 1)) ? 1 : 0;

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && minCost[r][c] + cost < minCost[nr][nc]) {
                    minCost[nr][nc] = minCost[r][c] + cost;

                    if (cost == 1) {
                        dque.push_back({nr, nc});
                    } else {
                        dque.push_front({nr, nc});
                    }
                }
            }
        }

        return minCost[m - 1][n - 1];
    }
};