class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        vector<int> bitCount(nums.size());
        for(int i=0; i<nums.size(); i++){
            bitCount[i] = __builtin_popcount(nums[i]);
        }
        int i=0;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int prevmaxi = INT_MIN;
        while(i<nums.size()){
            int k = bitCount[i];
            while(i<nums.size() && bitCount[i] == k){
                mini = min(nums[i],mini);
                maxi = max(nums[i],maxi);
                i++;
            }
            if(mini < prevmaxi) return false;
            prevmaxi = maxi;
            maxi = INT_MIN;
            mini = INT_MAX;
        }
        return true;
    }
};