class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // precompute number of ones
        int count1 = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == k)count1++;
        }
        int maxi = 0;
        for(int m=0; m<=50; m++){
            int count = 0;

            for(int i=0; i<nums.size(); i++){
                if(nums[i] == k)    count--;
                else if(nums[i] == m)   count++;
                if(count<0) count = 0;
                maxi = max(count, maxi);
            }
        }
        return (maxi + count1);
    }
};