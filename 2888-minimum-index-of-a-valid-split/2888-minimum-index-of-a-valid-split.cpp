class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int dom = nums[0];
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (cnt == 0) {
                dom = nums[i];
                cnt = 0;
            }
            if (nums[i] != dom)
                cnt--;
            else
                cnt++;
        }
        int c = 0;
        int split = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == dom)
                c++;
            else
                c--;
            if (c == 1) {
                split = i;
                break;
            }
        }
        int temp = split;
        if (split == nums.size() - 1)
            return -1;
        split++;
        c = 0;
        while (split < nums.size()) {
            if (nums[split] == dom)
                c++;
            else
                c--;
            split++;
        }
        if (c > 0) {
            return temp;
        } else {
            return -1;
        }
    }
};