class Solution {
public:
    int maxScore(string s) {
        int maxi = 0;
        for(int i=1; i<s.size(); i++){
                int zeros = 0;
                int ones = 0;
                for(int k=0; k<i;k++){
                    if(s[k] == '0')zeros++;
                }
                for(int k=i; k<s.size(); k++){
                    if(s[k] == '1')ones++;
                }
                maxi = max(maxi, zeros + ones);
        }
        return maxi;
    }
};