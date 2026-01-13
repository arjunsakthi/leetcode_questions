class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top=0,bottom=matrix.size()-1,left=0,right=matrix[0].size()-1;
        vector<int> ans;
        while(top<=bottom && left<=right) {
            for(int i=left; i<=right && top<=bottom;i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top; i<=bottom && left<=right;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            for(int i=right; i>=left && top<=bottom;i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
            for(int i=bottom; i>=top && left<=right;i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
        return ans;
    }
};