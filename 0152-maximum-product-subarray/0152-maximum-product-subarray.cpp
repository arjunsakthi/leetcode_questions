class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long sum = 1;
        long long maxi = *max_element(nums.begin(), nums.end());
        int low = 0;
        for(int high=0; high<nums.size(); high++){
            if(nums[high] == 0){
                while(low < high){
                    maxi = max(maxi, sum);
                    sum /= nums[low++];
                }
                low = high+1;
                sum = 1;
            }
            else{
                sum *= nums[high];
                maxi = max(maxi,sum);
            }
        }
        if(sum <0){
            while(sum<0 && low < nums.size()){
                sum /= nums[low];
                low++;
            }
            if(low < nums.size())
                maxi = max(maxi, sum);
        }
        return maxi;
    }
};