class Solution {
public:
    void f_rec(vector<vector<int>>& ans, vector<int> temp, vector<int>& candidates,int target, int k){
        if(target == 0 || k == candidates.size()){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }
        if(candidates[k] > target) return;
        temp.push_back(candidates[k]);
        f_rec(ans, temp, candidates, target - candidates[k], k);
        temp.pop_back();
        f_rec(ans, temp, candidates, target, k+1);
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        f_rec(ans, temp, candidates, target, 0);
        return ans;
    }
};