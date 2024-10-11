class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> chra(128,0);
        vector<char> matched(128,0);

        for(int i=0 ; i<s.size(); i++){
            
            if(chra[s[i]] == 0){
                    if(matched[t[i]] != 0) return false;
                
                chra[s[i]]  = t[i];
                matched[t[i]] = s[i];
            }
            else{
                if(chra[s[i]] != t[i]) return false;
            }
        }
        return true;
    }
};