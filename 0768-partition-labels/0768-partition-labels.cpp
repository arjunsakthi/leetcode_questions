class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> charFreq(26,0), windFreq(26,0);
        for(auto ch : s)
        {
            charFreq[ch-'a']++;
        }
        vector<int> ans;
        int start = 0;
        for(int i=0; i<s.size(); i++){
            int ch = s[i]-'a';
            windFreq[ch]++;
            if(check(charFreq,windFreq)){
                ans.push_back(i-start+1);
                start = i+1;
                windFreq.clear(); 
            }
        }
        return ans;
    }
    bool check(vector<int> &charFreq, vector<int> &windFreq){
        for(int i=0; i<26; i++){
            if(charFreq[i] != windFreq[i] && windFreq[i] != 0){
                return false;
            }
        }
        return true;
    }
};