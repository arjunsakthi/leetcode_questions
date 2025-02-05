class Solution {
public:

    bool compIfOne(string m1, string m2){
        int count = 0;
        for(int i=0; i<m1.size(); i++){
            if(m1[i] != m2[i])  count++;
        }
        return count == 1 || count == 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int flag = 0;
        for(string i : wordList){
            if(endWord == i)   { flag = 1;break;}
        }
        if(!flag) return 0;
        vector<int> visited(wordList.size(),0);
        queue<pair<string, int>>   bfs;
        bfs.push({beginWord,1});
        while(!bfs.empty()){
            pair<string,int> pp = bfs.front();
            string curr = pp.first;
            int val = pp.second;
            if(curr == endWord) return val;
            bfs.pop();
            for(int i=0; i<wordList.size(); i++){
                if(!visited[i] && compIfOne(curr,wordList[i])){
                    visited[i] = 1;
                    bfs.push({wordList[i], val+1});
                }
            }
        }
        return 0;
    }
};