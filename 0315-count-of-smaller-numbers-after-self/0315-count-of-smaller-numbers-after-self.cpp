class Solution {
public:
    int update(vector<int> &bitArray, int id){
        int sz = bitArray.size();   
        int s = id;
        id = sz - id;
        while(id < sz){
            bitArray[sz - id]++;
            id += (id & -id);
        }
        id = sz - s;
        int sum =0;
        while(id > 0){
            sum += bitArray[sz-id];
            id -= (id & -id);
        }
        return sum-1;
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> bitArray(nums.size()+1, 0);
        vector<int> ans(nums.size(),0);
        vector<pair<int,int>> arr(nums.size());
        for(int i=0; i<nums.size(); i++){
            arr[i] = {nums[i],i};
        }
        sort(arr.begin(),arr.end());
        for(auto i : arr){
            ans[i.second] = update(bitArray, i.second+1);
        }
       
    return ans;

    }
};