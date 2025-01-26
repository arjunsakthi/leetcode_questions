class Solution {
public:
    int candy(vector<int>& ratings) {
        // slope concept -- striver
        int i=1,n=ratings.size();
        int sum = 1; 
        while(i<n){
            if(ratings[i] == ratings[i-1]){
                sum += 1;
                i++;
                continue;
            }
            int peak = 1;
            while(i<n && ratings[i] > ratings[i-1]){
                peak++;
                sum += peak;
                i++;
            }
            int decr = 1;
            while(i < n && ratings[i] < ratings[i-1]){
                
                sum += decr;
                decr++;
                i++;
            }
            if(decr > peak){
                sum += decr - peak;
            }
        }
        return sum;
        // vector<int> choco(ratings.size(),1);
        // for(int i=1; i<ratings.size(); i++){
        //     if(ratings[i] > ratings[i-1]){
        //         choco[i] = choco[i-1] + 1;
        //     }
        // }
        // int count = 0;
        // for(int i=ratings.size()-2; i>=0; i--){
        //     if(ratings[i] > ratings[i+1] && choco[i] <= choco[i+1]){
        //         choco[i] = choco[i+1]+1;
        //     }           
        // }
        // int sum = accumulate(choco.begin(), choco.end(),0);
        // return sum;
    }
};