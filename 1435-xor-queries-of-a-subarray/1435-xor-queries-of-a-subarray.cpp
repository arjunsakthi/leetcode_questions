class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int size = arr.size();
        for(int i=1; i<size;i++)
            arr[i] = arr[i]^arr[i-1];
        
        vector<int> ans;
        for(auto &i:queries)
                ans.push_back((i[0] == 0)?arr[i[1]]:arr[i[0]-1]^arr[i[1]]);
        
        return ans;
    }
};