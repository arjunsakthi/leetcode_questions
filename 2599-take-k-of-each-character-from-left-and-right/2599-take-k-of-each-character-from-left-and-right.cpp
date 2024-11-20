class Solution {
public:
    int takeCharacters(string s, int k) {
        int mini = INT_MAX;
        int low=0; 
        int high=s.size();
        vector<int> tot(3,0);
        for(int i=0; i<s.size(); i++){
            tot[s[i]-'a']++;
        }
        while(low <= high){
            int mid = low + (high-low)/2;
            if(ispossible(s,mid,tot,k) != -1){
                mini = min(mini, (int)s.size() - mid);
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return mini == INT_MAX ? -1 : mini;
    }
private:
    int ispossible(string s, int k, vector<int> tot, int kat){
        // k window size
        // kat original k
        if(k == 0)  return check(tot,kat) == true ? 1 : -1;
        vector<int>  window(3,0);
        int mini = s.size();
        for(int i=0; i<k; i++){
            tot[s[i]-'a']--;
        }
        if(check(tot, kat))   return 1;
        for(int i=k; i<s.size(); i++){
            tot[s[i-k]-'a']++;
            tot[s[i]-'a']--;
            if(check(tot, kat))   return 1;
        }
        return -1;
    }
    bool check(vector<int> tot, int k){
        for(int i=0; i<3;i++){
            if(tot[i] < k) return false;
        }
        return true;
    }
};