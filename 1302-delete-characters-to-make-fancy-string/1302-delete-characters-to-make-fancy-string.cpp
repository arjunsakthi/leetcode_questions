class Solution {
public:
    string makeFancyString(string s) {
        int chr = s[0];
        int count = 0;
        string temp="";
        for(int i=0 ;i<s.size(); i++){
            if(s[i] != chr){
                chr = s[i];
                count = 0;
            }
            count++;
            if(count >= 3){
                continue;
            }
            temp += s[i];
        }
        return temp;
    }
};