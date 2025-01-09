class Solution {
public:

    int fun(vector<int> &nums, int k){
        int count = 0;
        int c = 0;
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2 != 0)  sum++;
            count++;
            while(sum > k){
                count--;
                if(nums[i - count]%2)   sum--;
            }
            c += count + 1;
        }
        return c;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return fun(nums,k) - fun(nums,k-1);
    }
};