class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> chra(26,0);
        vector<int> chra1(26,0);
        for(int i=0; i<s.size(); i++){
            chra[s[i]-'a']++;
        }
        for(int i=0; i<t.size();i++){
            chra1[t[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(chra[i] != chra1[i] )    return false;
        }
        return true;
    }
};