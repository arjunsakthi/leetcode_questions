class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       char ck;
       string prefix = "";
        for(int i=0;i<200;i++){
            if(strs[0].size() >= i+1)    ck = strs[0][i];
            for(string wrd : strs){
                if(wrd.size() < i+1)    return prefix;
                if(wrd[i] != ck)    return prefix;
            }
            prefix += ck;
        }
        return prefix;
    }
};