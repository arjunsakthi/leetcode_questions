class Solution {
public:
bool lcs(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    if(n >= m)  return false;
    if(m-n != 1)   return false;
    int k=1;
    int l=0;
    int i=0;
    while(i<n){
        if(s1[i] != s2[l]){
            if(k == 0)  return false;
            l++;
            k--;
        }
        else{
 l++;i++;
        }
           
    }
    return true;
}
    int longestStrChain(vector<string>& words) {
        vector<int> dp(words.size(),1);
        sort(words.begin(), words.end(),[](string &word1, string &word2){
            return word1.size() < word2.size();
        });
        int maxi = 1;
        int n = words.size();
        for(int i=0; i<n;i++){
            for(int j=0; j<i; j++){
                if(lcs(words[j],words[i])){
                    dp[i] = max(dp[i],dp[j]+1);
                    maxi = max(maxi,dp[i]);
                }
            }
        }
        return maxi;
    }
};