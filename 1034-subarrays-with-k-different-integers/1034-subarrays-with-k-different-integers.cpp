class Solution {
public:
    int fun(vector<int> &nums, int k){
        map<int,int> mpp;
        int count = 0;
        int left = 0;
        int countReturn = 0;
        for(int i=0; i<nums.size(); i++)
        {   
            mpp[nums[i]]++;
            if(mpp[nums[i]] == 1)   count++;
            while(count > k){
                mpp[nums[left]]--;
                if(mpp[nums[left]] == 0)   count--;
                left++;
            }
                countReturn += i - left + 1;
        }
        return countReturn;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return fun(nums, k) - fun(nums, k-1);
    }
};