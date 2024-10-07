class Solution {
public:
    int minLength(string s) {
        int cnt = 0;
        int i=0;
        int k = s.size()-1;
        while(i<k){
            cout << k <<" ";
            if(s[i] == 'A' && s[i+1] == 'B'){
                s.erase(s.begin()+i,s.begin()+i+2);
                i=0;
                continue;
            }
            if(s[i] == 'C' && s[i+1] == 'D'){
                 s.erase(s.begin()+i,s.begin()+i+2);
                 i=0;
                 continue;
            }
            i++;
        }
        return s.size();
    }
};