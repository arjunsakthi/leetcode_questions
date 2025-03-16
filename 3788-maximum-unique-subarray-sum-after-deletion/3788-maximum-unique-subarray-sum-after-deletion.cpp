class Solution {
public:
    int maxSum(vector<int>& nums) {
        map<int,int> mp;
        for(auto i : nums){
            if(i<0) continue;
            mp[i]++;
        }
        int sum =0;
        for(auto i : mp){
            sum += i.first;
        }
        if(mp.size() == 0){
            sum = *max_element(nums.begin(), nums.end());
        }
        return sum;
    }
};