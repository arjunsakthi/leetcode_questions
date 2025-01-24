class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> maxi(nums.size(),0);
        maxi[0] = nums[0];
        for(int i=1; i<nums.size(); i++){
            maxi[i] = max(maxi[i-1], i+nums[i]);
        }
        if(nums.size() == 1)    return 0;
        int last = nums.size()-1;
        int temp = -1;
        int count = 0;
        for(int i=nums.size()-1; i>=0; i--){
            if(maxi[i] >= last){
                temp = i;
            }
            else{
                last = temp;
                count++;
            }
            temp = i;
        }
        return count+1;
    }
};