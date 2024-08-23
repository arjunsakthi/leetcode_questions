class Solution {
public:
    string fractionAddition(string expression) {
        int num = 0;
        int denom = 1;

        int i = 0;
        while (i < expression.size()) {
            auto [currNum, currDenom] = parseFraction(expression, i);
            num = num * currDenom + currNum * denom;
            denom = denom * currDenom;
        }

        int gcd = abs(computeGCD(num, denom));
        num /= gcd;
        denom /= gcd;

        return to_string(num) + "/" + to_string(denom);
    }
    
    int computeGCD(int a, int b) {
        return b == 0 ? a : computeGCD(b, a % b);
    }

    pair<int, int> parseFraction(const string &expression, int &index) {
        int numerator = 0;
        int denominator = 0;
        bool isNegative = false;

        if (expression[index] == '-' || expression[index] == '+') {
            if (expression[index] == '-') {
                isNegative = true;
            }
            index++;
        }

        while (isdigit(expression[index])) {
            numerator = numerator * 10 + (expression[index] - '0');
            index++;
        }

        if (isNegative) {
            numerator *= -1;
        }

        index++;
        while (index < expression.size() && isdigit(expression[index])) {
            denominator = denominator * 10 + (expression[index] - '0');
            index++;
        }

        return {numerator, denominator};
    }
};
