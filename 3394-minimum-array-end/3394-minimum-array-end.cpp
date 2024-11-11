class Solution {
public:
    long long minEnd(int n, int x) {
        n--;
        long long k=0;
        long long l = x;
        for(long long i=0; i<64; i++){
                if((l & (long long)1<<(i) )== 0){
                    if(n&(1LL<<k)){
                        l = l|(1LL<<i);
                    }
                    k++;
                }
        }
        return l;
    }
};