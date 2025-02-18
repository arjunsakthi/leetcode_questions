class Solution {
public:
    vector<int> ans;

    string vectorToString(){
        string temp = "";
        for(auto i:this->ans){
            temp.push_back(i+'0');
        }
        return temp;
    }

    string smallestNumber(string pattern) {
        vector<int> used(10,0);
        vector<int> temp(pattern.size()+1,-1);
        for(int i=1; i<10; i++){
            temp[0] = i;
            used[i] = 1;
            if(rec(pattern, used, 1,temp))  break;
            temp[0] = -1;
            used[i] = 0;
        }
        return vectorToString();
    }
private:
    bool rec(string pattern,vector<int> &used, int ind, vector<int> &temp){
        if(ind - 1 == pattern.size()){
            ans = temp;
            return true;
        }

        for(int i=1; i<10; i++){
            if(used[i]) continue;
            else if((pattern[ind-1] == 'I' && temp[ind-1] < i) || (pattern[ind-1] == 'D' && temp[ind-1] > i)){
                temp[ind] = i;
                used[i] = 1;
                if(rec(pattern, used, ind+1, temp))   return true;
                temp[ind] = -1;
                used[i] = 0;
            }
        }
        return false;
    }
};