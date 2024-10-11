class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string temp="";
        int left = 0;
        int i = 0;
        while(left <s.size()){
            if(s[left] == ' '){
                if(temp != "" && i==0){
                    ans = temp;
                    i++;
                }
                else if(temp != ""){
                    ans = temp +" "+ans;
                }
                temp="";
            }
            else{
                temp += s[left];
            }
            left++;
        }
        if(temp != "" && ans.size() == 0) ans = temp +ans;
        else if(temp != "" && ans.size() != 0) ans = temp +" "+ans;
        return ans;
    }
};