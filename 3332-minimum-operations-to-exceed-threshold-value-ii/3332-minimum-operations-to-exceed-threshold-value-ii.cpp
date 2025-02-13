class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> qu;
        for(int i=0; i<nums.size(); i++){
            qu.push(nums[i]);
        }
        int count = 0;
        while(qu.size() >= 2 && qu.top() < k){
            count++;
            long long ele1 = qu.top();
            qu.pop();
            long long ele2 = qu.top();
            qu.pop();
            long long result = 2*ele1 + ele2;
            qu.push(result);
        }
        return count;
    }
};