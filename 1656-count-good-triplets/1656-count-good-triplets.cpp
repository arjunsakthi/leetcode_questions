class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int count = 0;
        multiset<int> ms;

            for(int j=1; j<arr.size()-1; j++){
                ms.insert(arr[j-1]);
                for(int k=j+1; k<arr.size(); k++){
                    int high = min(a + arr[j], c + arr[k]);
                    int low = max(arr[j] - a, arr[k] - c);
                    if(high < low)  continue;
                    int lower = distance(ms.begin(), ms.lower_bound( low));
                    int upper = distance(ms.begin(), ms.upper_bound( high));
                    if(abs(arr[j]-arr[k]) <= b)
                        count += upper - lower;
                }
            }
        
        return count;
    }
};