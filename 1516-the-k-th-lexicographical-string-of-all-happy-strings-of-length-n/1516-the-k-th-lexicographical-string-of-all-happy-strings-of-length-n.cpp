class Solution {
public:
    string ans = "";
    string getHappyString(int n, int k) {
        int num = 0;
        string temp = "";
        rec(n, k, num, temp);
        return ans;
    }

private:
    void rec(int n, int& k, int& num, string& temp) {

        if (n == 0) {
            num++;
            if (num == k) {
                ans = temp;
            }
            return;
        }
        for (int i = 0; i < 3; i++) {
            char ch = 'a' + i;
            if(!temp.empty() && temp.back() == ch)  continue;
            
            temp.push_back(ch);
            rec(n - 1, k, num, temp);
            temp.pop_back();
        }
        return;
    }
};