class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k)   return false;
        vector<int> hash(26,0);
        for(auto i : s){
            hash[i - 'a']++;
        }
        int count = 0;
        int c = 0;
        for(int i=0; i<26; i++){
            count += hash[i]/22;
            c += hash[i]%2; 
        }
        return c <= k;
    }
};
