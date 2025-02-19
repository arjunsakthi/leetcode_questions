class Solution {
public:
    string ans = "";
    string getHappyString(int n, int k) {
        int num = 0;
        string temp = "";
        bool hello = rec(n, k, num, temp);
        return hello ? ans: "";
    }

private:
    bool rec(int n, int& k, int& num, string& temp) {
        if (n == 0) {
            num++;
            if (num == k) {
                ans = temp;
                return true;
            }
            return false;
        }
        for (int i = 0; i < 3; i++) {
            char ch = 'a' + i;
            if(!temp.empty() && temp.back() == ch)  continue;
            
            temp.push_back(ch);
            if(rec(n - 1, k, num, temp)) return true;
            temp.pop_back();
        }
        return false;
    }
};