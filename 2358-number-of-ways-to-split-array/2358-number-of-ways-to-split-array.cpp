class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long> pre(nums.size(), 0);
        pre[0] = nums[0];
        for(int i=1; i<nums.size(); i++){
            pre[i] = nums[i] + pre[i-1];
        }
        int count = 0;
        for(int i=0; i<nums.size()-1; i++){
            long long front = pre[i];
            long long back = pre[nums.size()-1] - pre[i];
            if(front >= back)   count++;
        }
        return count;
    }
};