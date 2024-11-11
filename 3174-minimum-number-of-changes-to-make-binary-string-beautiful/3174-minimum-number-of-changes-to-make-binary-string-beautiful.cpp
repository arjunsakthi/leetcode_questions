class Solution {
public:
    int minChanges(string s) {
        int count = 1;
        int changes = 0;
        char prev = s[0];
        for(int i=1; i<s.size(); i++){
            if(s[i] != prev){
                if(count%2){
                    changes++;
                    count++;
                }
                else{
                    count=1;
                    prev=s[i];
                }
            }
            else{
                count++;
            }
        }
        return changes;
    }
};