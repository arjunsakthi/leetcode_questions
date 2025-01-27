class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i=0;
       auto front = lower_bound(intervals.begin(), intervals.end(), newInterval[0],[](vector<int> &element, int value){
        return element[0] < value;
       });
       intervals.insert(front, newInterval);
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