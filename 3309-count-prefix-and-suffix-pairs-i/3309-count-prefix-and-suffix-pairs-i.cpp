class Solution {
public:
    bool isPrefixAndSuffix(string s1, string s2){
        bool s11 = (s2.find(s1) == 0) ;
        if(s2.size() < s1.size())   return false;
        bool s22 = (s2.find(s1,s2.size() - s1.size()) != string::npos);
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