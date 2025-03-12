class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        auto neg = upper_bound(nums.begin(), nums.end(), -1);
        auto pos = upper_bound(nums.begin(),nums.end(),0);
        int negative =0;
        int positive=0;
            negative = neg - nums.begin();
        
     
            positive = nums.end() - pos;
    
        return max(positive,negative);
    }
};