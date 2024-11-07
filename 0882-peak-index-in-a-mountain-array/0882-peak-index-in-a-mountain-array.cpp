class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0;
        int n = arr.size();
        int high = n-1;
        while(low <= high){
            int mid = (low+high)/2;
            cout << mid <<endl;
            if(mid-1 >= 0 && mid+1 < n && arr[mid] > arr[mid-1] && arr[mid]>arr[mid+1]){
                return mid;
            }
            else if(mid+1 < n && arr[mid] > arr[mid+1]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return -1;
    }
};