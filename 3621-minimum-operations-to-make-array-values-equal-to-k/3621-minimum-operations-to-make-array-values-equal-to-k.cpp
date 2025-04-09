class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int mini = *min_element(nums.begin(),nums.end());
        if(mini < k)    return -1;
        sort(nums.begin(), nums.end());
        int distinct=0;
        int num=-1;
        for(int i=0; i<nums.size(); i++){
            if(num != nums[i])
            {
                distinct++;
                num=nums[i];
            }
        }
        return mini == k ? distinct-1 : distinct;
    }
};