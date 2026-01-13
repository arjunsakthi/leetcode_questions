class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int k=nums[0];
        int l=0;
        for(int i=0; i<nums.size(); i++){
            if(l==0) k=nums[i];
            if(k==nums[i]) l++;
            else l--;
        }
        return k;
    }
};