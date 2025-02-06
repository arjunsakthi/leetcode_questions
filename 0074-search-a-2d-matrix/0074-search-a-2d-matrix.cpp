class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;
        int high = matrix.size()-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(matrix[mid][m-1] >= target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        if(low == n){
            return false;
        }
        int ind = low ;
        low = 0;
        high = m-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(matrix[ind][mid] >= target){
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }
        if(matrix[ind][low] == target)  return true;
        else   return false;
    }
};