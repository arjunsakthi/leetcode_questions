class Solution {
public:
    int myAtoi(string s) {
        int flag = 0;
        int i=0;
        while(i<s.size() && s[i] == ' '){
            i++;
        }
        // if(i+1 == s.size()) return 0;
        if(s[i] == '-'){
            flag=1;
            i++;
        }
        else if(s[i] == '+'){
            i++;
        }
        int sum = 0;
        while(i<s.size()){
            if(s[i] >= '0' && s[i] <= '9'){
                int digit = s[i] - '0';

            // Check for overflow before updating sum
            if (sum > (INT_MAX - digit) / 10) {
                return flag ? INT_MIN : INT_MAX;
            }

            sum = sum * 10 + digit;
            }
            else{
                break;
            }
            i++;
        }
        return flag == 1 ?-sum:sum;
    }
};