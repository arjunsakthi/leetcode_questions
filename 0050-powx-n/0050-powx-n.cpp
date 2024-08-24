class Solution {
public:
    double myPow(double x, int n) {
        double y = 1;
        if(n == 0)  return 1;
        if(n<0){
            x = 1/x;
        }
        n = abs(n);
        while(n>1){
            if(n%2 == 0){
                x = x*x;
                n=n/2;
            }
            else{
                y = y*x;
                n=n-1;
            }
        }
        return y*x;
    }
};

