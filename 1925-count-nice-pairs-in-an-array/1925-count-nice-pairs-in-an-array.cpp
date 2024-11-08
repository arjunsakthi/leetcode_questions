class Solution {
public:
    int rev(int n){
        int k=0;
        while(n>0){
            int l = n%10;
            n /=10;
            k *= 10;
            k += l;
        }
        return k;
    }
    int countNicePairs(vector<int>& nums) {
        int MOD = 1000000007;
        map<int,int> mpp;
        for(int i=0; i<nums.size(); i++){
            int reve = rev(nums[i]);
            
            mpp[nums[i]-reve]++;
        }
        int sum = 0;
        for(auto i : mpp){
            cout << i.second <<endl;
            int count = i.second;
            sum = (sum + ( (1LL *count * (count - 1) )/ 2)%MOD) % MOD;
            sum %= MOD;
        }

        return sum;
    }
};