class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]> nums[j]){
                    int count1 =0;
                    int count2 = 0;
                    for(int k=0; k<14; k++){
                        if(nums[i]&(1<<k))  count1++;
                        if(nums[j]&(1<<k))  count2++;
                    }
                    if(count1 != count2)    return false;
                }
            }
        }
        return true;
    }
};