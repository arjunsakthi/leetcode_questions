class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> hash(ratings.size(), 0);
        vector<int> choco(ratings.size(),1);
        for(int i=1; i<ratings.size(); i++){
            if(ratings[i] > ratings[i-1]){
                choco[i] = choco[i-1] + 1;
            }
            else if(ratings[i] == ratings[i-1]){
                continue;
            }
            else{
                if(choco[i] == choco[i-1])
                    hash[i-1] += 1;
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