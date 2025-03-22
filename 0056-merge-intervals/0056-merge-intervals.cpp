class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int low =intervals[0][0];
        int high =intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            int l = intervals[i][0];
            int h = intervals[i][1];
            if(high < l){
                ans.push_back({low,high});
                low = l;
                high = h;
            }
            else{
                if(high < h){
                    high = h;
                }
            }
        }
        ans.push_back({low,high});
        return ans;
    }
};