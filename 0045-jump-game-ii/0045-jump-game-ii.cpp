class Solution {
public:
    int jump(vector<int>& nums) {
        int low = 0, high = 0;
        int jump = 0;
        while(high < nums.size()-1){
            int farthest = 0;
            for(int i=low; i<=high; i++){
                farthest = max(farthest, i+nums[i]);
            }
            low = high + 1;
            high = farthest;
            jump++;
        }
        return jump;
    }
};