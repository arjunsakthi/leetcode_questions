class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mp; // count sum and frequency
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                mp[nums[i] * nums[j]]++;
            }
        }
        int totalCount = 0;
        for (auto ele : mp) {
            int count = ele.second;
            if (count >= 2) {
                totalCount += ((count * (count - 1)) / 2) * 8;
            }
        }
        return totalCount;
    }
};