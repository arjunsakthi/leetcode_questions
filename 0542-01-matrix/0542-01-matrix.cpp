class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                } else {
                    dist[i][j] = -1;
                }
            }
        }

        int dR[] = {-1, 0, 1, 0}, dC[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int r = q.front().first, c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dR[i], nc = c + dC[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        return dist;
    }
};
