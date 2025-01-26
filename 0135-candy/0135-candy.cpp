class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> choco(ratings.size(),1);
        for(int i=1; i<ratings.size(); i++){
            if(ratings[i] > ratings[i-1]){
                choco[i] = choco[i-1] + 1;
            }
        }
        int count = 0;
        for(int i=ratings.size()-2; i>=0; i--){
            if(ratings[i] > ratings[i+1] && choco[i] <= choco[i+1]){
                choco[i] = choco[i+1]+1;
            }           
        }
        int sum = accumulate(choco.begin(), choco.end(),0);
        return sum;
    }
};