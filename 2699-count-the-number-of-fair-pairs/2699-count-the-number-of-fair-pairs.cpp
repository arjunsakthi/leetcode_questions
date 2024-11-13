class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        int low = nums.size()-1; 
        int high =  nums.size()-1;
        long long res=0;
        for(int i=0,j=nums.size()-1; i<j;i++){
            while(i < j && nums[i] + nums[j] > upper) j--;
            res += j-i;
        }
        for(int i=0,j=nums.size()-1; i<j;i++){
            while(i < j && nums[i] + nums[j] > lower-1) j--;
            res -= j-i;
        }
        return res;
    }
};