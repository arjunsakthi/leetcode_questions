class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int rowMax = mat[0].size();
        int colMax = mat.size();
        vector<pair<int,int>> hash(arr.size()+1, {-1,-1});
        vector<int> row(mat.size(), 0);
        vector<int> col(mat[0].size(), 0);
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                hash[mat[i][j]] = {i,j};
            }
        }
        for(int i=0; i<arr.size(); i++){
            int idxA = arr[i];
            pair<int,int> idxM = hash[idxA];
            row[idxM.first]++;
            col[idxM.second]++;
            if(row[idxM.first] == rowMax || col[idxM.second] == colMax)   return i;
        }
        return -1;
    }
};