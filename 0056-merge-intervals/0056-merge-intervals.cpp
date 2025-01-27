class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int i=0;
        sort(intervals.begin(), intervals.end());
       vector<int> prev = intervals[0];
       for(int i=1; i<intervals.size(); i++){
        if(prev[1] < intervals[i][0]){
            ans.push_back(prev);
            prev = intervals[i];
        }
        else{
            prev[1] = max(intervals[i][1],prev[1]);
        }
       }
       ans.push_back(prev);
        return ans;
    }
};