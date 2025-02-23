class Solution {
public:
    vector<int> parent, size;
    int pUltimate(int ele) {
        return parent[ele] = ele == parent[ele] ? ele : pUltimate(parent[ele]);
    }

    // union by size
    void Union(int ele1, int ele2) {

        int par1 = pUltimate(ele1);
        int par2 = pUltimate(ele2);
        if (par1 == par2)
            return;
        if (size[par1] > size[par2]) {
            size[par1] += size[par2];
            parent[par2] = par1;
        } else {
            size[par2] += size[par1];
            parent[par1] = par2;
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = n;

        vector<int> dx = {-1, +1, 0, 0};
        vector<int> dy = {0, 0, +1, -1};
        parent.resize(n * n);
        size.resize(n * n, 1);

        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                parent[i * n + j] = i * n + j;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int r = i;
                int c = j;

                if (grid[i][j] == 0)
                    continue;
                for (int j = 0; j < 4; j++) {
                    int rc = dx[j];
                    int cc = dy[j];
                    if (!(r + rc < 0 || r + rc >= n || c + cc < 0 ||
                          c + cc >= m) &&
                        grid[r + rc][c + cc] != 0) {
                        Union((r + rc) * n + (c + cc), r * n + c);
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int r = i;
                int c = j;
                if (grid[r][c] != 0) {
                    continue;
                }
                int count = 0;
                set<int> st;

                for (int j = 0; j < 4; j++) {
                    int rc = dx[j];
                    int cc = dy[j];
                    if (!(r + rc < 0 || r + rc >= n || c + cc < 0 ||
                          c + cc >= m) &&
                        grid[r + rc][c + cc] != 0) {

                        if (st.find(pUltimate((r + rc) * n + (c + cc))) ==
                            st.end()) {
                            st.insert(pUltimate((r + rc) * n + (c + cc)));
                            count += size[pUltimate((r + rc) * n + (c + cc))];
                        }
                    }
                }
                maxi = max(count + 1, maxi);
            }
        }
        maxi = max(maxi, size[0]);
        return maxi;
    }
};