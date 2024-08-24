class Solution {
public:
    int f_rec(vector<string>& words, vector<int>& count,int i, vector<int>& score, vector<int> dp) {
        if(i == words.size()){
            return 0;
        }
        int scores = 0;
        string word = words[i];
        vector<int> mps = count;
        for(int j=0; j<word.size(); j++){
            if(mps[word[j]-'a'] > 0){
                mps[word[j]-'a']--;
                scores += score[word[j]-'a'];
            }
            else{
                scores = 0;
                break;
            }
        }
        if(dp[i] != -1) return dp[i];
        int nottake = f_rec(words, count, i+1, score, dp);
        int take;
        if(scores == 0){
            take =  nottake;
        }
        else{
            take = scores + f_rec(words, mps, i+1, score, dp);
        }
        // cout << max(take, nottake)<<endl;
        return dp[i] = max(take, nottake);

    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> count(26,0);
        vector<int> dp(words.size(),-1);
        for(int i=0; i<letters.size(); i++){
            count[letters[i] - 'a']++;   
        }
        return f_rec(words, count, 0, score, dp);
    }
};