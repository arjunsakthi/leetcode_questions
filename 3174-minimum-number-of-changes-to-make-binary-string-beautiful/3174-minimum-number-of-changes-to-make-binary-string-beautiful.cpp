class Solution {
public:
    int minChanges(string s) {
        int count = 1;
        int changes = 0;
        for(int i=0; i<s.size()-1; i++){
            if(s[i] != s[i+1]){
                if(count%2){
                    s[i+1] = s[i];
                    changes++;
                    count++;
                }
                else{
                    count=1;
                }
            }
            else{
                count++;
            }
        }
        return changes;
    }
};