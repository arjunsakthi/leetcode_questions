class Solution {
public:
    void f(vector<int>& cand, int i, int target, vector<int>& temp, set<vector<int>>& ans) {
        
        if(target == 0) {
            ans.insert(temp);
        }
        if(target < 0 || i == cand.size()) return;

        f(cand, i+1, target, temp, ans);
        int a = cand[i];
        temp.push_back(a);
        f(cand, i+1, target-cand[i], temp, ans);
        f(cand, i, target-cand[i], temp, ans);
        temp.pop_back();
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int i=0;
        vector<int> temp;
        set<vector<int>> ans;
        f(candidates,i,target,temp,ans);
        return vector<vector<int>>(ans.begin(), ans.end());;
    }
};