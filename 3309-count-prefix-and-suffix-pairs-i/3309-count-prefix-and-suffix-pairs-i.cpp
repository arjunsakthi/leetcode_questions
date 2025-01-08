class Solution {
public:
    bool isPrefixAndSuffix(string s1, string s2){
        bool s11 = (s2.find(s1) == 0) ;
        reverse(s1.begin(), s1.end());
         reverse(s2.begin(), s2.end());
        bool s22 = (s2.find(s1) == 0);
        return s11 && s22;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for(int i=0; i<words.size(); i++){
            for(int j=i+1; j<words.size(); j++){
                if(i!=j && isPrefixAndSuffix(words[i], words[j])){
                    count++;
                }
            }
        }
        return count;
    }
};