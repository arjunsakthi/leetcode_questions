class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long total = 0;
        for(int i=0; i<nums.size(); i++){
            total += nums[i];
        }
        int count = 0;
        long long k = 0;
        for(int i=0; i<nums.size()-1; i++){
            k += nums[i];
            
            if(k >= total - k)   count++;
        }
        return count;
    }
};