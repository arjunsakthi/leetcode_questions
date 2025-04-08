class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxInd=0;
        for(int i=nums.size()-1; i>=0; i--){
            mp[nums[i]]++;
            if(mp[nums[i]] > 1){
                maxInd = max(maxInd, i+1);
            }
        }
        return ceil(maxInd/3.0);
    }
};