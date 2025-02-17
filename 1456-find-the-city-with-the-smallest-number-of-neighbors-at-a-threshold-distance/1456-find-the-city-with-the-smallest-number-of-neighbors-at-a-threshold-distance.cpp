class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n, vector<int>(n,-1));
        for(auto it : edges){
            mat[it[0]][it[1]] = it[2];
            mat[it[1]][it[0]] = it[2];
        }
        for(int via=0;via<mat.size(); via++){
            for(int i=0; i<mat.size(); i++){
                for(int j=0; j<mat.size(); j++){
                    if(mat[i][via] != -1 && mat[via][j] != -1 && (mat[i][via] + mat[via][j] < mat[i][j] || mat[i][j] == -1)){
                        mat[i][j] = mat[i][via] + mat[via][j];
                    }
                }
            }
        }
        int mini = 1e8;
        int miniCity = -1;
        for(int i=n-1; i>=0; i--){
            int count = 0;
            for(int j=0; j<n; j++){
                if(mat[i][j] <= distanceThreshold && i!=j)  count++;
            }
            cout << count << endl;
            if(count < mini){
                mini = count;
                miniCity = i;
            }
        }
        return miniCity;
    }
};