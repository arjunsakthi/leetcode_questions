class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        sort(quantities.begin(), quantities.end());
        int low = 1;
        int high = 100000;
        int ans = 1;
        while(low <= high){
            int mid = low + (high-low)/2;
            int ques = ispossible(n,quantities,mid);
            if( ques ){
                ans = mid;
                high = mid - 1;
            }

            else{
                low = mid + 1;
            }
        }
        return ans;
        return 0;
    }
    private:
    int ispossible(int n, vector<int>& quantities, int k){
        for(int i=0; i<quantities.size(); i++){
            n -= ceil((double)quantities[i]/(double)k);
        }
        return n>=0;
    }
};