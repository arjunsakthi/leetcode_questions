class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<long long> hash(10000005,0);
        for(int i=0;i<intervals.size();i++){
            hash[intervals[i][0]] += 1;
            hash[intervals[i][1]+1] += -1;
        }
        long long maxi=0;
        for(int i=1;i<10000005;i++){
            hash[i] += hash[i-1];
            maxi = max(hash[i],maxi);
        }
        return (int)maxi;
    }
};