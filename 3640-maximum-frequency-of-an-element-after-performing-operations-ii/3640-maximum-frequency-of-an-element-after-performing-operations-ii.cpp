class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int,int> hash;
        unordered_map<int,int> mpp;
        set<int> st;
        for(int i=0; i<nums.size(); i++){
            hash[nums[i]]++;
            mpp[nums[i]-k]++;
            mpp[nums[i]+k+1]--;
            st.insert(nums[i]-k);
            st.insert(nums[i]);
            st.insert(nums[i]+k+1);
        }
        int sum = 0;
        int maxi = 0;
        for(auto l : st){
            sum += mpp[l];
            int op = min(sum-hash[l],numOperations);
            maxi = max(maxi, hash[l]+op);
        }
        return maxi;
    }
};