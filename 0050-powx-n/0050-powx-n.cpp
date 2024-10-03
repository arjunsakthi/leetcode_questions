class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        int k = abs(n);
        while(k>0){
            if(k%2) ans = ans*x;
            if(k == 0)  break;
            k=k/2;
            x =x* x;
        }
        return n<0?1/(ans):ans;
    }
};