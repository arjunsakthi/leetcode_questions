class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        map<int,vector<int>> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]].push_back(i);
        }
        vector<int> ans;
        for(int i=0; i<queries.size(); i++)
        {
            int ind = queries[i];
            int ele = nums[ind];
            auto pos = lower_bound(mp[ele].begin(), mp[ele].end(), ind);
            cout << ele << " " << mp[ele].size() << endl;
            if(mp[ele].size() == 1){
                ans.push_back(-1);
            }
            else{
                int mini = INT_MAX;
                int nd = pos - mp[ele].begin();
                int sz = mp[ele].size();
                cout << nd;
                if(nd == 0){
                    mini = min(mini, (int)nums.size() - mp[ele][sz-1] + ind);
                }
                if(nd == sz-1){
                    mini = min(mini, (int)nums.size() - ind + mp[ele][0]);
                }
                if(nd > 0){
                    mini = min(mini,  ind - mp[ele][nd-1]);
                }
                if(nd < sz-1){
                    mini = min(mini, mp[ele][nd+1] - ind);
                }
                ans.push_back(mini);
            }
        }
        return ans;
    }
};