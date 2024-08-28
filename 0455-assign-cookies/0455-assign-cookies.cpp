class Solution {
public:
    // int f_rec(int n, vector<int>& g, vector<int>& s, int hashc, int childc){
    //     if(hashc == 0 || n == 0){
    //         if(hashc == 0 && n == 0)    return childc;
    //     }
    // }
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int k=0, i=0;
        while(i<g.size() && k < s.size()){
            if(g[i]<=s[k]){
                i++;
            }
            k++;
        }
        return i;
    }
};