class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int> mpp;
        int maxii = 0;
        int count = 0;
        for(int i=0; i<s.size(); i++){
            mpp[s[i]]++;
            count++;
            int maxi = 0;
            for(auto j : mpp){
                maxi = max(maxi, j.second);
            }
            if(count - maxi <= k){
                
                maxii = max(maxii, count);
            }
            else{
                count--;
                mpp[s[i - count]]--;
            }
        }
        return maxii;
    }
};