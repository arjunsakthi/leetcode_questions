class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &np1,vector<int> &np2){return np1[1] == np2[1] ? np1[0] < np1[0] : np1[1] < np2[1];});
        int endTime = INT_MIN;
        int count = 0;
        for(int i=0; i<intervals.size(); i++){
            if(intervals[i][0] >= endTime){
                count++;
                endTime = intervals[i][1];
            }
        }
        return intervals.size() - count;
    }
};