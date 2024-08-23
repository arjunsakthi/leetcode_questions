class Solution {
public:
    string fractionAddition(string exp) {
        int num = 0, denom = 1;

        int i = 0;
        while (i < exp.size()) {
            auto [n, d] = parseFraction(exp, i);
            num = num * d + n * denom;
            denom *= d;
        }

        int gcd = abs(computeGCD(num, denom));
        num /= gcd;
        denom /= gcd;

        return to_string(num) + "/" + to_string(denom);
    }

    int computeGCD(int a, int b) {
        return b == 0 ? a : computeGCD(b, a % b);
    }

    pair<int, int> parseFraction(const string &exp, int &idx) {
        int n = 0, d = 0;
        bool neg = false;

        if (exp[idx] == '-' || exp[idx] == '+') {
            neg = (exp[idx] == '-');
            idx++;
        }

        while (isdigit(exp[idx])) {
            n = n * 10 + (exp[idx] - '0');
            idx++;
        }

        if (neg) n *= -1;

        idx++;
        while (idx < exp.size() && isdigit(exp[idx])) {
            d = d * 10 + (exp[idx] - '0');
            idx++;
        }

        return {n, d};
    }
};
