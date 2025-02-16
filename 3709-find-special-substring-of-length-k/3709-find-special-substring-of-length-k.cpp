
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
        int count =0 ;
        for(int j=i; j<min(i+k,(int)s.size()); j++){
            if(s[j] != ch)  {valid = false;break;}
            count++;
        }
        if(flag && (count == k))  return true;
      }
      return false;
    }
};