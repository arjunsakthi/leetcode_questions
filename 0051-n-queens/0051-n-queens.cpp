class Solution {
public:
    bool isPossible(int row, int col, int n, vector<string> temp) {
        for(int i=row+1; i<n; i++) {
            if(temp[i][col] == 'Q') return false;
        }
        int i=row+1, j=col+1;
        while (i<n && j<n) {
            if(temp[i][j] == 'Q') return false;
            i++;
            j++;
        }
        i=row+1;
        j=col-1;
        while (i<n && j>=0) {
            if(temp[i][j] == 'Q') return false;
            i++;
            j--;
        }
        return true;
    }

    void f(int idx, int n, vector<string> temp, vector<vector<string>> &ans) {
        if (idx == -1) {
            ans.push_back(temp);
            return;
        }

        for (int i=0; i<n; i++) {
            temp[idx][i] = 'Q';
            if(isPossible(idx, i, n, temp))
                f(idx-1,n,temp,ans);
            temp[idx][i] = '.';
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp(n, string(n,'.'));
        vector<vector<string>> ans;
        f(n-1, n, temp, ans);
        return ans;
    }
};