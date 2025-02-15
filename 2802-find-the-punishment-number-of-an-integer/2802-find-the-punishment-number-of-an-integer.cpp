class Solution {
public:
    int punishmentNumber(int n) {
        int sum = 0;
        for(int i=1; i<=n; i++){
            int sz = sizeOfNumber(i*i);
            if(canItMake(i,i*i,sz)){
                cout << i << endl;
                sum += i*i;
            }
        }
        return sum;
    }
private: 
    bool canItMake(int required, int number, int sz){
        if(required < 0)    return false;
        if(sz == 0){
            return required == 0;
        }
        int c = 10;
        for(int i=1; i<=sz; i++){
            int chopped = number%(c);
            if(canItMake(required - chopped, number/(c), sz-i))   return true;
            c *= 10;
        }
        return false;
    }
    int sizeOfNumber(int number){
        int count = 0;
        while(number > 0){
            number = number/10;
            count++;
        }
        return count;
    }
};