class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        int ind = 0;
        vector<vector<int>> freq(n+1,vector<int>());
        vector<int> temp, ans;
        rec(ind, freq, n, temp, ans);
        return ans;
    }
private:
    bool rec(int ind, vector<vector<int>> &freq, int &n, vector<int> &temp, vector<int> &ans){
        if(ind == 2*n - 1){
            ans = temp;
            return true;
        }
        for(int i=n; i>=1; i--){
            if(i == 1 && freq[i].size() == 1)   continue;

            if(freq[i].size() == 0 || (freq[i].size() == 1 && abs(find(temp.begin(), temp.end(), i)-temp.begin()- ind) == i)){
                freq[i].push_back(ind);
                temp.push_back(i);
                if(rec(ind+1, freq, n, temp, ans))  return true;
                freq[i].pop_back();
                temp.pop_back();
            }
        }
        return false;
    }
};