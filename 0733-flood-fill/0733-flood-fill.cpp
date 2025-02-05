class Solution {
private:
    void dfs(int r, int c, vector<vector<int>>& img, int col, int dR[], int dC[], int ini) {
        img[r][c] = col;
        int n = img.size(), m = img[0].size();
        for (int i = 0; i < 4; i++) {
            int nr = r + dR[i], nc = c + dC[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && img[nr][nc] == ini && img[nr][nc] != col)
                dfs(nr, nc, img, col, dR, dC, ini);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ini = image[sr][sc];
        if (ini == color) return image;
        int dR[] = {-1, 0, 1, 0}, dC[] = {0, 1, 0, -1};
        dfs(sr, sc, image, color, dR, dC, ini);
        return image;
    }
};
