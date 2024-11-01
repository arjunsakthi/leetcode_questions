class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        int i=0;
        int k=0;
        while(i<goal.size()){
            if(goal[i] == s[0]){
                int j=i;
                while(j<goal.size() && goal[j] == s[k]){
                    j++;
                    k++;
                }
                if(j == goal.size()){
                    j=0;
                    while(k<s.size() && goal[j] == s[k]){
                        j++;
                        k++;
                    }
                    if(k == goal.size())    return true;

                }
                k=0;
                i++;
            }
            else{
                i++;
            }
        }
        return false;
    }
};