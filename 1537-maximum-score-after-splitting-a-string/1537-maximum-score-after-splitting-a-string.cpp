class Solution {
public:
    int maxScore(string s) {
        int one = count(s.begin(),s.end(),'1');
        
        int ans = 0,zero=0;
        for(int j = 0; j<s.size()-1; j++){
            char i = s[j];
            zero+=i=='0'?1:0;
            one-=i=='1'?1:0;
            ans = max(ans,zero+one);
        }
        int l = s.size();
        return ans == l ? ans:ans;
    }
};