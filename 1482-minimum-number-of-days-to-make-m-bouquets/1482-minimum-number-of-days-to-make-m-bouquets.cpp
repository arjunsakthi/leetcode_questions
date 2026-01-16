class Solution {
public:
    int minDays (vector<int>& bloomDay, int m, int k) {
        if (m > bloomDay.size() / k) return -1;
        int low = 1;
        int ans = -1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        while (low <= high) {
            int mid = (low + high) / 2;
            if (bloomMid(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }

bool bloomMid(vector<int>& bloomDay, int m, int k, int mid) {
    int bouquets = 0;
    int cnt = 0;

    for (int i = 0; i < bloomDay.size(); i++) {
        if (bloomDay[i] <= mid) {
            cnt++;
            if (cnt == k) {
                bouquets++;
                cnt = 0;   // reset after making bouquet
            }
        } else {
            cnt = 0;       // break the consecutive chain
        }
    }
    return bouquets >= m;
}
 
};