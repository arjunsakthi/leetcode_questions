class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int c=0;
        int low=1;
        for(int i=0; i<arr.size(); i++) {
            for(int j=low; j<arr[i]; j++) {
                c++;
                if(c==k)    return j;
            }
            low=arr[i]+1;
        }
        for(int j=low; j<2005; j++) {
            c++;
            if(c==k) return j; 
        }
        return -1;
    }
};