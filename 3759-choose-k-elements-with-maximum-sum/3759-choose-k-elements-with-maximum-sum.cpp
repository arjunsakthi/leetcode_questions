class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2,
                                 int k) {
        vector<pair<int, pair<int, int>>> temp(
            nums1.size()); // nums1 nums2 index
        for (int i = 0; i < nums1.size(); i++) {
            temp[i] = {nums1[i], {nums2[i], i}};
        }
        sort(temp.begin(), temp.end());
        for (int i = 0; i < nums1.size(); i++) {
            cout << temp[i].first << " " << temp[i].second.first << endl;
        }
        priority_queue<int, vector<int>, greater<int>> minipq;
        vector<long long> ans(nums1.size(), 0);
        long long sum = 0;
        long long tempSum = 0;
        for (int i = 0; i < temp.size(); i++) {
            tempSum = sum;
            int flag = 0;
            if (i == 0) {
                minipq.push(temp[i].second.first);
                sum += temp[i].second.first;
                k--;
                continue;
            }
            if (k > 0) {
                flag = 1;
                minipq.push(temp[i].second.first);
                sum += temp[i].second.first;
                k--;
            } else if (minipq.top() < temp[i].second.first) {
                flag = 1;
                sum -= minipq.top();
                minipq.pop();
                minipq.push(temp[i].second.first);
                sum += temp[i].second.first;
            } 
            if (temp[i - 1].first < temp[i].first) {
                cout << sum - (flag ? temp[i].second.first : 0) << endl;
                ans[temp[i].second.second] = tempSum;
            } else {
                cout << ans[temp[i - 1].second.second] << endl;
                ans[temp[i].second.second] = ans[temp[i - 1].second.second];
            }
        }
        return ans;
    }
};