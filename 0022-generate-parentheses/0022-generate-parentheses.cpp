class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        fun(s, n, n, ans, n);
        return ans;
    }

    void fun(string& s, int open, int close, auto& ans, int n){
        if(open==0 && close==0) {
            ans.push_back(s);
            return ;
        }
        if(open<0 || close<0) return ;

        if(close<open) return;

        s.push_back('(');
        fun(s, open-1, close, ans, n);
        s.pop_back();
        s.push_back(')');
        if (close > open) fun(s, open, close-1, ans, n);
        s.pop_back();
    }
};