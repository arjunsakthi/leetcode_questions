class Solution {
public:
    string smallestNumber(string pattern) {
       pattern = 'I'+pattern;
        int incI = 1;
        int decI = 1;
        int j = 0;
        string ans = "";
        while(j < pattern.size()){
            int inc=0;
            int dec=0;
            while(j<pattern.size() && pattern[j] == 'I')inc++,j++;
            while(j<pattern.size() && pattern[j] == 'D')dec++,j++;
            while(inc > 1) ans.push_back('0'+incI),incI++,inc--;
             incI += dec; ans.push_back('0'+incI);inc--;
             decI = incI-1;
             incI++;
            while(dec > 0) ans.push_back('0'+decI),decI--,dec--;
        }
        return ans;
    }  
};