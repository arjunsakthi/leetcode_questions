class Solution {
public:
    bool ispalidrome(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void f(string s, int idx, vector<string> temp, vector<vector<string>> &ans) {
        if (idx == s.size()) {
            ans.push_back(temp);
        }

        for (int i=idx; i<s.size(); i++) {
            string firstSub = s.substr(idx, i-idx+1);
            if (!ispalidrome(firstSub)) continue;
            temp.push_back(firstSub);
            f(s,i+1,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;
        int i=0;
        f(s,i,temp,ans);
        return ans;
    }
};