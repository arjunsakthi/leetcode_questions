class Solution {
public:
    bool whetherCanRob(vector<int> &nums, int &k, int mini){
        vector<vector<int>> dp(nums.size()+1, vector<int>(2,0));
        for(int i=1; i<=nums.size(); i++){
            for(int j=0; j<=1; j++){
                if(j==0){
                    dp[i][j] = max((nums[i-1] <= mini ?1:0)+dp[i-1][1], dp[i-1][0]);
                }
                else{
                    dp[i][j] = dp[i-1][0];
                }
            }
        }
        cout << max(dp[nums.size()][0],dp[nums.size()][1]) << " " << mini<<endl;
        return max(dp[nums.size()][0],dp[nums.size()][1]) >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int low =0;
        int high =1000000000;
        int ans =0;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(whetherCanRob(nums,k,mid)){
                high = mid - 1;
                ans=mid;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};