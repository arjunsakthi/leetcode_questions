class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for(int i=0; i<words.size(); i++){
            int count = 0;
            for(int j=0; j<words.size(); j++){
                if(words[j].find(words[i]) != string::npos)    count++;
            }
            if(count > 1)   ans.push_back(words[i]);
        }
        return ans;
    }
};