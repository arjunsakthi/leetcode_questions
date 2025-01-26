class Solution {
public:

    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2;
       vector<vector<int>> lf(n+1), rf(n+1);
       // bitmask for both left and right
       for(int i=0; i<(1<<n); i++){
        int sz = 0;
        int l =0;
        int r=0;
        for(int j=0; j<n; j++){
            if(i&(1<<j)){
                sz++;
                l += nums[j];
                r += nums[j+n];
            }
        }
        lf[sz].push_back(l);
        rf[sz].push_back(r);
       }
       // sort right half
       for(int i=0; i<=n; i++){
        sort(rf[i].begin(),rf[i].end());
       }
       // x element from left and n-x from right give array 1
       // then abs(sum - 2*(left + right)) minimum of all
       int totalSum = accumulate(nums.begin(), nums.end(),0);
       int res = INT_MAX;
       for(int i=1; i<=n; i++){
        for(auto a : lf[i]){
            int reqb = totalSum/2 - a;
            auto b = lower_bound(rf[n-i].begin(), rf[n-i].end(), reqb);
            if(b != rf[n-i].end()){
                int part1 = a + *b;
                // absolute diff of both arrays is sum - 2*part1
                res = min(res, abs(totalSum - 2*part1));
            }
            if(b != rf[n-i].begin()){
                int part1 = a + *(--b);
                res = min(res, abs(totalSum - 2*part1));
            }
        }
       }
       return res;
    }
};