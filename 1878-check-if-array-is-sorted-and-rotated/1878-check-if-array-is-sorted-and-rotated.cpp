class Solution {
public:
    bool check(vector<int>& nums) {
        if(nums.size() == 1)    return true;
        int flag = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] < nums[i-1] ){
                if(flag)    flag = 0;
                else return false;
            } 
        }
        if(!flag){
            if(nums[0] < nums[nums.size()-1]){
                return false;
            }
        }
        
        return true;
    }
};