class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        int c =0;
        for(int i=0; i<nums.size(); i++){
            if(pivot == nums[i])c++;
            if(nums[i] < pivot)ans.push_back(nums[i]);
        }
        for(int i=0; i<c; i++){
            ans.push_back(pivot);
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > pivot){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};