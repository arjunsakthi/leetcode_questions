class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> diffarr(s.size()+1,0);
        for(int i=0; i<shifts.size(); i++){
            vector<int> shift = shifts[i];
            diffarr[shift[0]] += shift[2] == 1? 1 : -1;
            diffarr[shift[1]+1] += shift[2] == 1? -1 : 1;
        }
        for(int i=1; i<diffarr.size(); i++){
            diffarr[i] += diffarr[i-1];
        }
        int MOD = 26;
        for(int i=0; i<s.size(); i++){
            int c = s[i] - 'a';
            c += diffarr[i];
            c %= MOD;
            c += MOD;
            c %= MOD;
            c += 'a';
            s[i] = char(c);
        }
        return s;
    }
};