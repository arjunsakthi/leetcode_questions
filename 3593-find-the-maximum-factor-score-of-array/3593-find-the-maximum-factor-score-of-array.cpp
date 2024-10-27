class Solution {
public:

    long long lcm(long long a, long long b){
        return (a*b)/gcd(a,b);
    }

    long long maxScore(vector<int>& nums) {
        long long gcdd = 0;
        long long lcmm = 1;
        long long maxfactor = 0;
        for(int i=0; i<nums.size(); i++){
                gcdd = gcd(gcdd,nums[i]);
                lcmm = lcm(lcmm,nums[i]);
        }
        maxfactor = max(maxfactor,gcdd*lcmm);
        for(int i=0; i<nums.size(); i++){
            long long gcddd = 0;
            long long lcmmd = 1;
            for(int j=0; j<nums.size();j++){
                if(i!=j){
                    gcddd = gcd(gcddd,nums[j]);
                    lcmmd = lcm(lcmmd,nums[j]);
                }
            }  
            maxfactor = max(maxfactor,gcddd*lcmmd);
        }
        return maxfactor;
    }

private:
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
