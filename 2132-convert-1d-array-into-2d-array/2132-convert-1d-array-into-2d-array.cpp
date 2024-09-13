class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int i=1,size=original.size();
         vector<vector<int>> ans;
         vector<int> row;
        while(i<=size){
            row.push_back(original[i-1]);
            if(m == 0) return {};
            if(i%n == 0){
                ans.push_back(row);
                m--;
                row = {};
            } 
            i++;
        }
        if(m != 0)  return {};
        return ans;
    }
};