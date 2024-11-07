class Solution {
public:
bool lcs(string s1, string s2) {
if(s1.size() != s2.size()+1) 
            return false;
        
        int first = 0;
        int second = 0;
        
        while(first < s1.size()){
            
            if(s1[first] == s2[second] && second < s2.size()){
                first++;
                second++;
            }else{
                first++;
            }
        }
        
        if(first == s1.size() && second == s2.size()) 
            return true;
        
        return false;
}
    static bool comp(string &s1, string &s2){
        
        return s1.size() < s2.size();
        
    }
    int longestStrChain(vector<string>& words) {
        vector<int> dp(words.size(),1);
        sort(words.begin(), words.end(),comp);
        int maxi = 1;
        int n = words.size();
        for(int i=0; i<n;i++){
            for(int j=0; j<i; j++){
                if(lcs(words[i],words[j])){
                    dp[i] = max(dp[i],dp[j]+1);
                    maxi = max(maxi,dp[i]);
                }
            }
        }
        return maxi;
    }
};