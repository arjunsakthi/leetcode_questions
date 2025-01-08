class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int mini = INT_MAX;
        int sum = 0;
        for(int i=0; i<cardPoints.size()-k;i++){
            sum += cardPoints[i];
        }
        mini = min(mini, sum);
        for(int i=cardPoints.size() - k;i<cardPoints.size(); i++){
            sum += cardPoints[i];
            sum -= cardPoints[i- cardPoints.size() + k];
            mini = min(mini, sum);
        }
        return accumulate(cardPoints.begin(), cardPoints.end(),0) - mini;
    }
};