class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> diffarr(s.size()+1,0);
        for(int i=0; i<shifts.size(); i++){
            vector<int> shift = shifts[i];
            diffarr[shift[0]] += shift[2]*2 - 1;
            diffarr[shift[1]+1] += shift[2]*2*(-1) + 1;
        }
        int MOD = 26;
        int c = s[0] - 'a';
            c += diffarr[0];
            c %= MOD;
            c += MOD;
            c %= MOD;
            c += 'a';
            s[0] = c;
        for(int i=1; i<s.size(); i++){
            diffarr[i] += diffarr[i-1];
            int c = s[i] - 'a';
            c += diffarr[i];
            c %= MOD;
            c += MOD;
            c %= MOD;
            c += 'a';
            s[i] = c;
        }
        return s;
    }
};