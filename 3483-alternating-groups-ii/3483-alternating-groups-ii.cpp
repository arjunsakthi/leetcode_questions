class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int l =0 ;
        int r=1;
        int sum =0;
        int mod = colors.size();
        for(r=0; r<mod+k-1; r++){
            if(r!=0 && colors[r%mod] == colors[(r-1)%mod]){
                l = r;
            }
            if(r - l + 1 < k)   continue;
            sum++;
            l++;
        }
        return sum;
    }
};