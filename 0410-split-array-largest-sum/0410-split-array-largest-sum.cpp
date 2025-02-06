class Solution {
public:
    bool check(vector<int>& nums, int k, int sum){
        int count = 0;
        int tempSum = 0;
        for(int i=0; i<nums.size(); i++){
            tempSum += nums[i];
            if(tempSum > sum){
                count++;
                tempSum = nums[i];
            }
        }
        count++;
        return count <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 1);
        while(low <= high){
            int mid = low + (high - low)/2;
            if(check(nums,k,mid)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};