class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0;
        int count = 0;
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(sum >= goal){
                count += mpp[sum - goal];
            }
            mpp[sum]++;
        }
        return count;
    }
};