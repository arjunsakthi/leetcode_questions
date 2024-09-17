class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> mpp;
        string temp = "";
        vector<string> ans;
        for(int i=0; i<=s1.size(); i++){
            if(s1[i] == ' ' || i == s1.size()){
                mpp[temp]++;
                temp = "";
                continue;
            }
            temp+=s1[i];
        }
        temp = "";
        for(int i=0; i<=s2.size(); i++){
            if(s2[i] == ' ' || i == s2.size()){
                mpp[temp]++;
                temp = "";
                continue;
            }
            temp+=s2[i];
        }
        for(auto i:mpp){
            if(i.second == 1){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};