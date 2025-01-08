class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi = 0;
        int start = 0;
        unordered_map<char,int> alpha;
        for(int i=0; i<s.size(); i++){
            if( alpha[s[i]] == 0)  alpha[s[i]]++;
            else{
                maxi = max(i-start, maxi);
                int j = start;
                while(j < i && alpha[s[i]] != 0){
                    alpha[s[j]]--;
                    j++;
                }
                start = j;
                alpha[s[i]]++;
            }
        }
        maxi = max(maxi, (int)s.size() - start);
        return maxi;
    }
};