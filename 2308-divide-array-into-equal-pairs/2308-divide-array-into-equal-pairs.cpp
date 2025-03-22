class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ele=-1;
        int count = 0;
        for(int i=0; i<nums.size();i++){
            if(ele != nums[i]){
                if(count&1) return false;
                count=0;
                ele = nums[i];
            }
                     count++;
      
            
        }
        return count&1 ? false:true;
    }
};