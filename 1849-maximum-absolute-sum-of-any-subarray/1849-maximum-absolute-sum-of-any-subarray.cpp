class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int prefsum =0;
        int mini = 0;
        int maxi = 0;
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            prefsum += nums[i];
            mini = min(prefsum,mini);
            maxi = max(prefsum,maxi);
            ans = max(ans,prefsum-mini);
            ans = max(ans,abs(prefsum - maxi));
        }
    return ans;
    }
};