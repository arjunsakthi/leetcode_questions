class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        string temp="";
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                if(cnt == 0){
                    cnt++;
                    continue;
                }
                cnt++;
                temp+=s[i];
            }
            else{
                cnt--;
                if(cnt == 0){
                    continue;
                }
                temp+=s[i];
            }
        }
        return temp;
    }
};