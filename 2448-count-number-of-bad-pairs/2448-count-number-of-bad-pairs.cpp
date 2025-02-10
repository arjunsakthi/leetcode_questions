class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        map<int,int> frequency;
        for(int i=0; i<nums.size(); i++){
            nums[i] = i - nums[i];
            frequency[nums[i]]++;
        }
        long long count = 0;
        for(auto it : frequency){
            int num = it.first;
            int ct = it.second;
            if(it.second > 1){
                count += (ct*1LL*(ct-1))/2;
            }
        }
        int n = nums.size();
        return (n*1LL*(n-1))/2 - count;
        
    }
};