class Solution {

private:
    void dfs(int r, int c, vector<vector<char>>& board, int dR[], int dC[]) {
        int n = board.size(), m = board[0].size();
        board[r][c] = '#';
        for (int i = 0; i < 4; i++) {
            int nr = r + dR[i], nc = c + dC[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && board[nr][nc] == 'O')
                dfs(nr, nc, board, dR, dC);
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        int dR[] = {-1, 0, 1, 0}, dC[] = {0, 1, 0, -1};

        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O')
                dfs(0, j, board, dR, dC);
            if (board[n - 1][j] == 'O')
                dfs(n - 1, j, board, dR, dC);
        }

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O')
                dfs(i, 0, board, dR, dC);
            if (board[i][m - 1] == 'O')
                dfs(i, m - 1, board, dR, dC);
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                board[i][j] = (board[i][j] == '#') ? 'O' : 'X';
    }
};