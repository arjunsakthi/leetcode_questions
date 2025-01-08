class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int N = cardPoints.size();
        int sum = 0, r = N - 1;
        for (int l = 0; l < k; l++)
            sum += cardPoints[l];
        int ans = sum;
        for (int l = k - 1; l >= 0; l--) {
            sum -= cardPoints[l];
            sum += cardPoints[r--];
            ans = max(ans, sum);
        }
        return ans;
    }
};