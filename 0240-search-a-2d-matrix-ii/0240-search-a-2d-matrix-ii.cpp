class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i=0; i<matrix.size(); i++) {
            int idx = lower_bound(matrix[i].begin(), matrix[i].end(), target) - matrix[i].begin();
            if (idx == matrix[i].size()) continue;
            if (matrix[i][idx] == target) return true;
        }
        return false;
    }
};