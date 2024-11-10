class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int sum = 0;
        int mini = INT_MAX;
        int i=0;
        while(i<nums.size()){
            sum = nums[i] | sum;
            if(sum >=k){
                int temp= 0;
                int j=i;
                while(j >=0 && temp < k){
                    temp = temp|nums[j];
                    j--;
                }
                mini = min(mini, i-j);
                sum = 0;
                i=j+1;
            }
            i++;
        }
        return k==0 ? 1 : (mini == INT_MAX)? -1:mini;
    }
};