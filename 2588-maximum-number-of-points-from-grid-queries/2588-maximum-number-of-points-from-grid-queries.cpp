class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> qu;
        vector<vector<int>> visited(grid.size(),
                                    vector<int>(grid[0].size(), 0));
        vector<int> ans(queries.size(), 0);
        vector<pair<int, int>> queryIndexs;
        vector<int> dx = {-1, 0, 0, +1};
        vector<int> dy = {0, -1, +1, 0};
        for (int i = 0; i < queries.size(); i++) {
            queryIndexs.push_back({queries[i], i});
        }
        sort(queryIndexs.begin(), queryIndexs.end());
        qu.push({grid[0][0], 0, 0});
        visited[0][0] = 1;
        int count = 0;
        for (int i = 0; i < queryIndexs.size(); i++) {
            int ind = queryIndexs[i].second;
            int ele = queryIndexs[i].first;

            while (!qu.empty() && qu.top()[0] < ele) {
                vector<int> top = qu.top();
                int x = top[1];
                int y = top[2];
                qu.pop();

                count++;

                for (int j = 0; j < 4; j++) {
                    if (x + dx[j] >= 0 && x + dx[j] < grid.size() &&
                        y + dy[j] >= 0 && y + dy[j] < grid[0].size() &&
                        !visited[x + dx[j]][y + dy[j]]) {
                        visited[x + dx[j]][y + dy[j]] = 1;
                        qu.push(
                            {grid[x + dx[j]][y + dy[j]], x + dx[j], y + dy[j]});
                    }
                }
            }
            ans[ind] = count;
        }
        return ans;
    }
};