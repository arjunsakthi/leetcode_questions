class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> s1;
        vector<string> s2;
        string temp = "";
        for(int i=0; i<=sentence1.size();i++){
            if(i == sentence1.size() || sentence1[i] == ' '){
                s1.push_back(temp);
                temp = "";
                continue;
            }
            temp += sentence1[i];
        }
        temp ="";
        for(int i=0; i<=sentence2.size();i++){
            if(i == sentence2.size() || sentence2[i] == ' '){
                s2.push_back(temp);
                temp = "";
                continue;
            }
            temp += sentence2[i];
        }
        if(s1.size()>s2.size()){
            swap(s1,s2);
        }
        int start=0,end=0;
        while(start<s1.size() && s1[start] == s2[start]) start++;
        while(end<s1.size() && s1[s1.size()-1-end] == s2[s2.size()-1-end]) end++;
        cout <<start <<end << s1.size();
        return start+end >= s1.size();

    }
};