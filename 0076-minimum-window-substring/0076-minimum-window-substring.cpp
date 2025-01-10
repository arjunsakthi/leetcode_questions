class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> bCount = freqCount(t);
        vector<int> aCount(52, 0);
        int left = 0;
        int mini = INT_MAX;
        int l=-1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] > 'Z')
                aCount[s[i] - 'a' + 26]++;
            else
                aCount[s[i] - 'A']++;
            while (okCheck(aCount, bCount)) {
                if(mini > i-left +1){
                    mini = min(mini, i - left + 1);
                    l = left;
                }
                
                if (s[left] > 'Z')
                    aCount[s[left] - 'a' + 26]--;
                else
                    aCount[s[left] - 'A']--;
                left++;
            }
        }
        return (l == -1)? "" : s.substr(l,mini);
    }

private:
    vector<int> freqCount(string& str) {
        vector<int> hash(52, 0);
        for (int i = 0; i < str.size(); i++) {
            if (str[i] > 'Z')
                hash[str[i] - 'a' + 26]++;
            else
                hash[str[i] - 'A']++;
        }
        return hash;
    }
    int okCheck(vector<int>& str1, vector<int>& str2) {
        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] < str2[i]) {
                return 0;
            }
        }
        return 1;
    }
};