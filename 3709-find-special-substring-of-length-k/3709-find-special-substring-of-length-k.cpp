
class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
      for(int i=0; i<s.size(); i++){
        bool flag = true;
        if(i>0 && s[i] == s[i-1]) {
            flag = false;
        }
        if(i+k < s.size() && s[i+k] == s[i+k-1]){
            flag = false;
        }
        char ch = s[i];
        bool valid = true;
        for(int j=i; j<i+k; j++){
            if(s[j] != ch)  {valid = false;break;}
        }
        if(flag && valid)  return true;
      }
      return false;
    }
};