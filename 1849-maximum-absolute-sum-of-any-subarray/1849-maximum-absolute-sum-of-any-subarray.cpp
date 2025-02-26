class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum =0;
        int maxi = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(sum < 0){
                sum=0;
            }
            else{
                maxi = max(sum, maxi);
            }
        }
        sum=0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(sum > 0){
                sum=0;
            }
            else{
                maxi = max(abs(sum), maxi);
            }
        }
    return maxi;
    }
};