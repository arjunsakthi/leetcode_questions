class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int l = 0;
        int i = 0;
        int sum =0;
        int mod = colors.size();
        while (i < colors.size() + k - 1) {
            while (i < colors.size() + k - 1 && (l == 0 || (colors[i%mod] != colors[(i - 1)%mod] && l != k))) {
                l++;
                i++;
            }
            if(l == k){
                sum++;
                l--;
            }
            else{
                l=0;
            }
        }
        return sum;
    }
};