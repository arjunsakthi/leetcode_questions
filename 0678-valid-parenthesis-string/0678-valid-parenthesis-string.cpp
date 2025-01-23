class Solution {
public:
    bool checkValidString(string s) {
        int maxi = 0;
        int mini = 0;
        for(char i : s){
            if(i == '('){
                maxi++;
                mini++;
            }
            else if(i == ')'){
                maxi--;
                mini--;
            }
            else{
                    mini--;
                maxi++;
            }
            if(mini < 0) mini = 0;
            if(maxi < 0)    return false;
        }
        return (mini == 0);
    }
}; 