class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxi = 0;
            for(int j=0; j<32; j++){
                int count = 0;
                for(int i=0; i<candidates.size(); i++){
                    if(candidates[i]&(1<<j))  count++;
            }
            maxi = max(count,maxi);
        }
        return maxi;
    }
};