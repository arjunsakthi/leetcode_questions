class Solution {


public:
    int climbStairs(int n) {
        int prev = 1,
         prev1 = 0,
         curr = 0;
        for(int i=0; i<n; i++){
            curr = prev + prev1;
            prev1 = prev;
            prev = curr;
        }
        return curr;
    }
};