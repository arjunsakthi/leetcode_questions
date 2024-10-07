class Solution {
public:
    int myAtoi(string s) {
        int flag = 0; // To check for negative numbers
        int i = 0;

        // Skip leading spaces
        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        // Handle the sign if present
        if (i < s.size() && s[i] == '-') {
            flag = 1;
            i++;
        } else if (i < s.size() && s[i] == '+') {
            i++;
        }

        long sum = 0;
        while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';

            // Check for overflow before updating sum
            if (sum > (INT_MAX - digit) / 10) {
                return flag ? INT_MIN : INT_MAX;
            }

            sum = sum * 10 + digit;
            i++;
        }

        // Apply negative sign if flag is set
        return flag ? -sum : sum;
    }
};
