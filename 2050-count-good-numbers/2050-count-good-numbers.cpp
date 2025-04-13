class Solution {
public:
    int mod;
    int countGoodNumbers(long long n) {
        mod = 1000000007;
        long long even = (n+1)/2;
        long long odd = n/2;
        long long ans = (powerf(5,even) *1LL* powerf(4,odd))%mod;
        return ans;
    }
private:
    long long powerf(long long a, long long b){
        long long res=1;
        while(b>0){
            if(b&1)res = (res*1LL*a)%mod;
            a = (a*1LL*a)%mod;
            b >>= 1;
        }
        return res;
    }
};