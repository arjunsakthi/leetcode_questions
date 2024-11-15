class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int prefup = 1;
        for(int i=0; i<arr.size()-1; i++){
            if(arr[i] > arr[i+1])
                break;
            else
                prefup++;
        }
        if(prefup == arr.size())    return 0;
        
        prefup--;
        int prefdw = 1;
        for(int i=arr.size()-1; i>0; i--){
            if(arr[i] < arr[i-1])   break;
            else prefdw++;
        }
        int maxi = arr.size()-max(prefup+1,prefdw);
        prefdw = arr.size()-prefdw;
        
        for(int i=0, j=prefdw; i<=prefup && j<arr.size();){
            if(arr[i] <= arr[j]){
                maxi = min(maxi, j-i-1);
                i++;
            }
            else{
                j++;
            }
        }
        return maxi;
    }
};