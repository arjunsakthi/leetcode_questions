class Solution {
public:
    bool canJump(vector<int>& nums) {
        int required = 0;
        for(int i=nums.size()-1; i>=0; i--){
            if(nums[i] >= required){
                required = 0;
            }
                required++;

        }
        return required == 1;
    }
};