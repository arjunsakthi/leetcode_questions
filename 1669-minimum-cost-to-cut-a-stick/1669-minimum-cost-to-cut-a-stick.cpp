class Solution {
public:
    int minC(int low, int high, vector<int> &cuts){
        if(high < low) return 0;
        int mini = INT_MAX;
        for(int i=low; i<=high; i++){
            int minc = minC(low, i-1,cuts) + minC(i+1,high,cuts) + cuts[high+1]-cuts[low-1];
            mini = min(mini, minc);
        }
        return mini;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());
        // return minC(1,cuts.size()-2,cuts);
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        for(int i=m-2; i>0; i--){

            for(int j=i; j<m-1;j++){
                int mini = INT_MAX;

            for (int ind = i; ind <= j; ind++) {
                int ans = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j];

                mini = min(mini, ans);
            }

            dp[i][j] = mini;
            }
        }

        return dp[1][m - 2];
    }
};
