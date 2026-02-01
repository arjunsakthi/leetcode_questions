class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool isThere = false;
        int low = 0;
        int high = matrix.size()-1;
        int index = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (matrix[mid][0] <= target && matrix[mid][matrix[0].size()-1] >= target) {
                index = mid;
                break;
            }
            else if (matrix[mid][0] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        if (index == -1) return false;
        low = 0;
        high = matrix[0].size()-1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (matrix[index][mid] == target) return true;
            else if (matrix[index][mid] > target) high = mid - 1;
            else low = mid + 1;
        } 
        return false;
    }
};