class Solution {
public:
    int divide(int dividend, int divisor) {
        int neg = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

        if (dividend == 0) {
            return 0;
        }
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        int q = 0;
        long long divd = dividend;
        divd = abs(divd);
        long long divs = divisor;
        divs = abs(divs);
         for (int i = 31; i >= 0; i--) {  // Iterate from MSB to LSB for efficiency
            if (divd >= (divs << i)) {
                divd -= (divs << i);
                q += (1 << i);
            }
        }
        return q == INT_MIN ? q: neg*q;
    }
};