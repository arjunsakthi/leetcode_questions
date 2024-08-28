class Solution {
public:
    string removeOccurrences(string s, string part) {
        int start = 0;
        while(s[start] != '\0'){
            if(s[start]==part[0]){
                int k = start;
                int l = 0;
                while(s[k] != '\0' && l<part.size()){
                    if(s[k] != part[l]) break;
                    k++;
                    l++;
                }
                if(l == part.size()){
                    s.erase(start, l);
                    start = 0;
                    continue;
                }  
            }
            start++;
        }
        return s;
    }
};