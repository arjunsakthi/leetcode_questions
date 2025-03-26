class Solution {
public:
    int seive(int n){
        vector<int> seive(n,0);
        int c=0;
        for(int i=3; i<n; i+=2){
            if(!seive[i]){
                c++;
                for(int j=i*i; j<n; j+=i){
                    seive[j]=1;
                }
            }
        }
        return n>2 ? c+1 : c;
    }
    int countPrimes(int n) {
        return seive(n);
    }
};