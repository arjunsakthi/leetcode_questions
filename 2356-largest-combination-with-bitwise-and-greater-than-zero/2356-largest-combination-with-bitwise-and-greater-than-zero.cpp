class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        map<int,int> mpp;
        for(int i=0; i<candidates.size(); i++){
            for(int j=0; j<32; j++){
                if(candidates[i]&(1<<j))  mpp[j]++;
            }
        }
        int maxi = 0;
        for(auto k : mpp){
            maxi = max(k.second,maxi);
        }
        return maxi;
    }
};