class Solution {
public:
long long int solve(vector<int>& nums){
    int n = nums.size();
    long long int prev = nums[0];
    long long int prev2 =0;
    
    for(int i=1; i<n; i++){
        long long int pick = nums[i];
        if(i>1)
            pick += prev2;
        int long long nonPick = 0 + prev;
        
        long long int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;
        
    }
    return prev;
}

    int rob(vector<int>& nums) {
 vector<int> arr1;
    vector<int> arr2;
    int n = nums.size();
    
    if(n==1)
       return nums[0];
    
    for(int i=0; i<n; i++){
        
        if(i!=0) arr1.push_back(nums[i]);
        if(i!=n-1) arr2.push_back(nums[i]);
    }
    
    long long int ans1 = solve(arr1);
    long long int ans2 = solve(arr2);
    
    return max(ans1,ans2);
};
};