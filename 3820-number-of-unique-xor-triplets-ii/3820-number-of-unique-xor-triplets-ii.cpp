
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int S = 2048;
        int n = nums.size();
        
        // Rolling DP: two 2D arrays
        vector<vector<int>> prev(S, vector<int>(3, 0));
        vector<vector<int>> curr(S, vector<int>(3, 0));
        
        // Base initialization at index 0 (mimicking your original base)
        prev[0][1] = 1;             // dp[0][0][1] = 1
        prev[nums[0]][0] = 1;         // dp[0][nums[0]][0] = 1
        prev[nums[0]][2] = 1;         // dp[0][nums[0]][2] = 1
        
        // Process from i = 1 to n-1
        for (int i = 1; i < n; i++) {
            // Clear current DP array
            for (int j = 0; j < S; j++) {
                curr[j][0] = curr[j][1] = curr[j][2] = 0;
            }
            
            for (int j = 0; j < S; j++) {
                // Compute XOR index with current element
                int exor = (j ^ nums[i]) & 2047;
                
                // Transition for state 0
                if (j == nums[i]) curr[j][0] |= 1;  // If current XOR equals nums[i]
                curr[j][0] |= prev[j][0];
                
                // Transition for state 1
                curr[j][1] |= prev[j][1];
                curr[j][1] |= prev[exor][0];
                
                // Transition for state 2
                curr[j][2] |= prev[j][2];
                curr[j][2] |= prev[exor][1];
                curr[j][2] |= prev[j][0];
            }
            // Roll current DP to previous DP for next iteration
            prev.swap(curr);
        }
        
        int sum = 0;
        for (int j = 0; j < S; j++) {
            if (prev[j][2]) sum++;
        }
        return sum;
    }
};
