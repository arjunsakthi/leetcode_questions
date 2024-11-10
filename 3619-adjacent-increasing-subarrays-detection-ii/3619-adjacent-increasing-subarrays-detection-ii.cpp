class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        vector<int> prefup(nums.size(),1);
        int maxi = 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] > nums[i-1]){
                prefup[i] += prefup[i-1];
            }
        }
        auto check = [&](int k){
            if(k==0)    return true;
            for(int i=0; i+2*k-1<nums.size(); i++){
                if(prefup[i+k-1]-prefup[i] == k-1 && prefup[i+2*k-1] - prefup[i+k] == k-1){
                    return true;
                }
            }
            return false;
        };
        int left = 0;
        int right = nums.size()/2;
        while(left <=right){
            int mid = left + (right - left)/2;
            cout << mid<<endl;
            cout << check(mid) <<endl;
            if(check(mid)){
                maxi = mid;
                
                left = mid +1;
            }
            else{
                right = mid -1 ;
            }
        }
        return maxi;
    }
};