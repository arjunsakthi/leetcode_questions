class Solution {
public:
    void update(vector<int> &bitset, int n, int op){
        for(int i=0; i<32; i++){
            if(n&(1<<i)){
                bitset[i] += op;
            }
        }
    }
    bool check(vector<int> bitset, int k){
        int n  =0;
        for(int i=0; i<32; i++){
            if(bitset[i]){
                n |= (1<<i);
            }
        }
        return k<=n;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int sum = 0;
        int mini = INT_MAX;
        int i=0;
        int left = 0; 
        int right = 0;
        vector<int> bitset(32,0);
        while(right < nums.size()){
            update(bitset, nums[right],1);
            if(check(bitset, k)){
                while(left <= right && check(bitset,k)){
                    mini = min(mini, right-left+1);
                    update(bitset, nums[left],-1);
                    left++;
                }
            }
            right++;
        }
        return k==0 ? 1 : (mini == INT_MAX)? -1:mini;
    }
};