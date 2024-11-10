class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int inv = 1;
        int count = 1;
        vector<int> prefup(nums.size(),1);
        for(int i=1; i<nums.size(); i++){
            if(nums[i] > nums[i-1]){
                prefup[i] += prefup[i-1];
            }
        }
        for(int i=0; i+2*k-1<nums.size(); i++){
            if(prefup[i+k-1]-prefup[i] == k-1 && prefup[i+2*k-1] - prefup[i+k] == k-1){
                return true;
            }
        }
        return false;
    }
};