class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        vector<int> count(1e5+2,0);
        vector<int> sum(1e5+2,0);
        int MOD = 1000000007;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                count[0] += (1 + count[1])%MOD;
                count[0] %= MOD;
                sum[0] += (sum[1])%MOD;
                sum[0] %= MOD;
            }
            else
            {
                count[nums[i]] += (1 + count[nums[i]+1]%MOD + count[nums[i]-1]%MOD)%MOD;
                count[nums[i]] %= MOD;
                sum[nums[i]] +=(int)(nums[i] + (sum[nums[i]+1]%MOD + count[nums[i]+1]*1LL*nums[i]%MOD)%MOD+(sum[nums[i]-1]%MOD + count[nums[i]-1]*1LL*nums[i]%MOD)%MOD)%MOD;
                sum[nums[i]] %= MOD;

            }

        }
        int sums = 0;
        for(int i=0; i<sum.size(); i++){
            sums = (sums + sum[i])%MOD;
        }
        return sums;
    }
};