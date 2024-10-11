class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        for(int i=0; i<s.size();i++){
            int k=0;
            for(int j=i; j<s.size();j++){
                if(goal[k] != s[j]) break;
                k++;
            }
            cout << i << k <<goal.size()<<endl;
            if(k == 0)  continue;
            
            for(int j=0;j<i;j++){
                if(goal[k] != s[j]) break;
                k++;
            }
            if(k == goal.size())    return true;
            
        }
        return false;
    }
};