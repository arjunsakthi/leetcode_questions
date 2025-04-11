class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i=low; i<=high; i++){
            string number = to_string(i);
            if(number.size()%2) continue;
            int sum = 0;
            for(int j=0; j<number.size()/2; j++){
                sum += number[j]-'0';
            }
            int sum2 = 0;
            for(int j=number.size()/2; j<number.size(); j++){
                sum2 += number[j]-'0';
            }
            if(sum == sum2)count++;
        }
        return count;
    }
};