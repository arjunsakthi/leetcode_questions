class Solution {
public:
 int mergeSort(vector<int> &arr, int low, int high){
        int count =0;
        if(low == high) return 0;
        int mid = low + (high-low)/2;
        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid+1, high);
        count += merge(arr, low, mid, high);
        return count;
    }
    int merge(vector<int> &arr, int low, int mid, int high){
        int l1=low, l2=mid+1;
        int r1=mid, r2=high;
        vector<int> temp;
        int count=0;
        while(l1<=r1 && l2<=r2){
            if(arr[l1] > 2*1LL*arr[l2]){
                count += (r1-l1+1);
                l2++;
            }
            else{
                l1++;
            }
        }
        l1=low;
        l2=mid+1;
        while(l1<=r1 && l2<=r2){
            if(arr[l1] > arr[l2]){
                temp.push_back(arr[l2]);
                l2++;
            }
            else{
                temp.push_back(arr[l1]);
                l1++;
            }
        }
        while(l1 <= r1){
            temp.push_back(arr[l1]);
            l1++;
        }
        while(l2 <= r2){
            temp.push_back(arr[l2]);
            l2++;
        }
        int ind=0;
        for(int i=low; i<=high; i++){
            arr[i] = temp[ind++];
        }
        return count;
    }
    int reversePairs(vector<int>& nums) {
        int count = mergeSort(nums,0,nums.size()-1);
        return count;
    }
};