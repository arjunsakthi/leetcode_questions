class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        for(int i=1; i<items.size();i++){
           items[i][1] =  max(items[i-1][1], items[i][1]);
        }
        vector<int> ans;
        for(int k : queries){
           int bsearch = upper_bound(items.begin(), items.end(), k, 
                                      [](int val, const vector<int>& a) { return val < a[0]; }) 
                          - items.begin() - 1;
            if(bsearch < 0){
                ans.push_back(0);
            }else{
                ans.push_back(items[bsearch][1]);
            }
        }
        return ans;
    }
};