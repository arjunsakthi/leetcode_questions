class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> chra(128);

        for(int i=0 ; i<s.size(); i++){
            
            if(chra[s[i]] == 0){
                for(int j=0; j<chra.size();j++){
                    if(chra[j] == t[i]) return false;
                }
                chra[s[i]]  = t[i];
            }
            else{
                if(chra[s[i]] != t[i]) return false;
            }
        }
        return true;
    }
};