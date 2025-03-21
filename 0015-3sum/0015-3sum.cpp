class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        for (int i = 0; i < nums.size(); i++) {
            int num1 = nums[i];
            int req = -nums[i];
            int low = i + 1;
            int high = nums.size() - 1;
            while (low < high) {
                if (nums[low] + nums[high] == req) {
           
                        st.insert({num1, nums[low], nums[high]});
               
                    high--;
                    low++;
                } else if (nums[low] + nums[high] < req) {
                    low++;
                    while (low < high && nums[low] == nums[low - 1])
                        low++;
                } else {
                    high--;
                    while (low < high && nums[high] == nums[high + 1])
                        high--;
                }
            }
        }
        vector<vector<int>> ans;
        for (auto i : st) {
            ans.push_back(i);
        }
        return ans;
    }
};