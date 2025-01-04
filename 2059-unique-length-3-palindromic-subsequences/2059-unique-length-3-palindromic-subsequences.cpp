class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int,int>> mp(26,{-1,-1});
        vector<vector<int>> charcount(s.size()+1, vector<int>(26,0));
        for (int i=0; i<s.size(); i++){
            if(mp[s[i]-'a'].first == -1){
                mp[s[i]-'a'].first = i;
            }
            else{
                mp[s[i]-'a'].second = i;
            }
            charcount[i + 1] = charcount[i];
            charcount[i+1][s[i]-'a']++;
        }
        int maxCount = 0;
        for(int i=0; i<26; i++){
            if(mp[i].first != -1 && mp[i].second != -1){
                int first = mp[i].first+1;
                int second = mp[i].second;
                if(second - first > 0){
                    int count = 0;
                    vector<int> vfirst = charcount[first];
                    vector<int> vsecond = charcount[second];
                    cout << first << " " << second << endl<<endl;
                    for(int j=0; j<26; j++){
                        if(vsecond[j]-vfirst[j]){
                            count++;
                        }  
                    }
                    maxCount += count;
                }    
            }
        }
        return maxCount;

    }
};