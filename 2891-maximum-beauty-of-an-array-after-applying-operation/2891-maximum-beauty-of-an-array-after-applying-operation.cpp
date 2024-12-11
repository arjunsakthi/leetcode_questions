class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<int> hash(1e5+2,0);

        for(auto i : nums){
            int low = max(0,i-k);
            int high = min(100000,i+k);
            hash[low]++;
            hash[high+1]--;
        }
        int maxi = 0;
        for(int i=1; i<1e5+2; i++){
            hash[i] += hash[i-1];
            maxi = max(hash[i],maxi);
        }
        return maxi;
    }
    
};