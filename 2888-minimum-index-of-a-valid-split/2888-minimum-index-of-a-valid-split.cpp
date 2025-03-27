class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int dom = nums[0];
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (cnt == 0) {
                dom = nums[i];
                cnt = 0;
            }
            if (nums[i] != dom)
                cnt--;
            else
                cnt++;
        }
        int c = 0;
        for(auto i : nums){
            if(i == dom)    c++;
        }
        int k=0;
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] == dom)
                k++;
            if(k>(i+1)/2 && c-k > (nums.size()-1-i)/2){
                return i;
            }
        }
       
            return -1;
        
    }
};