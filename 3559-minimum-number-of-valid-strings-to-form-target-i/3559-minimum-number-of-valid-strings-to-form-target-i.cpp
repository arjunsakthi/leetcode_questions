class TrieNode{
        public:
            TrieNode *ch[26];
            bool isEnd;
            TrieNode(){
                for(int i=0;i<26;i++){
                    ch[i] = NULL;
                }
                isEnd = false;
            }
    };

class Solution {
public:
    
    class Trie{
        public:
            TrieNode* root;
            Trie(){
                root = new TrieNode();
            }
            
            void insert(string &s){
                int n = s.size();
                TrieNode* t = root;
                for(int i=0;i<n;i++){
                    int k = s[i]-'a';
                    if(t->ch[k] == NULL){
                        t->ch[k] = new TrieNode();
                    }
                    t = t->ch[k];
                }
                t->isEnd = true;
            }

            int search(string &s, int i, int n, int dp[]){
                if(i == n)  return 0;
                TrieNode * t = root;
                int ans=1e4;
                if(dp[i] != -1) return dp[i];
                for(int j=i;j<n;j++){
                    int k = s[j]-'a';
                    if(t->ch[k] != NULL){
                        ans = min(ans,search(s,j+1,n,dp)+1);
                        t = t->ch[k];
                    }
                    else break;
                }
                return dp[i] = ans;
            }
    }
;

    int func(int tar,vector<string> &words, string target,vector<int> &dp){
        if(target.size() == tar){
            return 0;
        }
        int get = tar;
        int maxi = 0;
        int mini = INT_MAX;
        if(dp[tar] != -2)   return dp[tar];
        for(int i=0; i<words.size(); i++){
            int cnt=0;            
            for(int j=tar;j<target.size();j++){
                if(target[j] != words[i][j-tar])  break;
                cnt++;
            } 
            maxi = max(cnt,maxi);
        }
        for(int i=1; i<=maxi; i++){
            int k = func(tar+i,words,target,dp);
            if(k != -1)
                mini = min(1+k,mini);
        }
        if(mini == INT_MAX) return -1;
        return dp[tar] = mini;

    }

    int minValidStrings(vector<string>& words, string target) {
        Trie trie; 
        int dp[10001];
        memset(dp, -1, sizeof(dp));
        for(auto i:words){
            trie.insert(i);
        }
        int n=target.size();
        int ans = trie.search(target,0,n,dp);
        return ans == 1e4 ? -1:ans;
    }
};