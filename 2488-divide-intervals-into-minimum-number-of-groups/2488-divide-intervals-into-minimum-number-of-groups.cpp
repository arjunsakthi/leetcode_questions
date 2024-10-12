class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<pair<int,int>> spp;
        for(int i=0;i<intervals.size();i++){
            spp.push_back({intervals[i][0],1});
            spp.push_back({intervals[i][1]+1,-1});
        }
        sort(spp.begin(),spp.end());
        int maxi=0,cnt=0;
        for(int i=0;i<spp.size();i++){
            cnt += spp[i].second;
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};