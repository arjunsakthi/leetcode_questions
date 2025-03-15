class Solution {
public:
    bool whetherCanRob(vector<int> &nums, int &k, int mini){
        int count =0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] <= mini){
                i++;
                count++;
            }
        }
        return count >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int low =0;
        int high =1000000000;
        int ans =0;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(whetherCanRob(nums,k,mid)){
                high = mid - 1;
                ans=mid;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};