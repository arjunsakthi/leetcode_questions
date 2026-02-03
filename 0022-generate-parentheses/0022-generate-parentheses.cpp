class Solution {
public:
    void f(int &n, int i, vector<string> &ans, string temp) {
        if (i == 2*n) {
            int c = 0;
            for(int i=0; i<temp.size(); i++) {
                if (temp[i] == '(') c++;
                else c--;
                if (c < 0) return;
            }
            if(c == 0) ans.push_back(temp);
            return;
        }
        temp.push_back('(');
        f(n,i+1,ans,temp);
        temp.pop_back();
        temp.push_back(')');
        f(n,i+1,ans,temp);
        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int i=0;
        string temp;
        f(n,i,ans,temp);
        return ans;
    }
};