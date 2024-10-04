class Solution {
public:
    long long dividePlayers(vector<int>& s) {
        int t = 0;
        for(int i = 0; i < s.size(); i++) {
            t += s[i];
        }   
        long long p = 0;
        sort(s.begin(), s.end());
        int r = s[0] + s[s.size() - 1]; 
        for(int j = 0; j < s.size() / 2; j++) {
            if(s[j] + s[s.size() - j - 1] != r) return -1;
            p += s[j] * s[s.size() - j - 1];
        }
        return p;
    }
};
