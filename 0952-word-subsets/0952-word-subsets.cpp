class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> w2(26, 0);
        vector<string> ans;
        for (int i = 0; i < words2.size(); i++) {
            vector<int> hash(26, 0);
            string temp = words2[i];
            for (int j = 0; j < temp.size(); j++) {
                hash[temp[j] - 'a']++;
                w2[temp[j]-'a'] = max(w2[temp[j] - 'a'], hash[temp[j] - 'a']);
            }
    
        }
        for (int i = 0; i < words1.size(); i++) {
            string temp = words1[i];
            vector<int> hash(26, 0);
            int flag = 0; for (int j = 0; j < temp.size(); j++) {
                hash[temp[j] - 'a']++;
            }
            for (int j = 0; j < 26; j++) {
                if (hash[j] < w2[j]) {
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                ans.push_back(temp);
            }
        }
        return ans;
    }
};