class Solution {
public:
    string largestOddNumber(string num) {
        int i;
        for(i=num.size()-1; i>=0; i--){
            if((num[i]-'0')%2 != 0) break;
        }
        string temp="";
        for(int j=0; j<=i;j++){
            temp += num[j];
        }
        return temp;
    }
};