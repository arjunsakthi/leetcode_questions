class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();

        vector<int> u(n, 0), d(n, 0);

        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) u[i] = u[i - 1] + 1;
        }

        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) d[i] = d[i + 1] + 1;
        }

        int maxi = 0;
        for (int i = 1; i < n - 1; i++) {
            if (u[i] > 0 && d[i] > 0) {  
                maxi = max(maxi, u[i] + d[i] + 1);
            }
        }

        return maxi;
    }
};
