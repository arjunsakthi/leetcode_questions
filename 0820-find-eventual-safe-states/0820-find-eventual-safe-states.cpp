class Solution {
public:
    // 2 means pathVisited and 1 means visited
    // Only need to check whether they are cycle or not from each node
    // if cycle then return all the element in the cycle
    void dfs(int ind, vector<vector<int>> &adj, vector<int> &visited, vector<int> &temp, set<int> &ans){
        visited[ind] = 2;
        vector<int> eleArr = adj[ind];
        temp.push_back(ind);
        for(int i=0; i<eleArr.size(); i++){
            if(!visited[eleArr[i]]){
                dfs(eleArr[i], adj, visited, temp, ans);
            }
            else if(visited[eleArr[i]] == 2 || ans.find(eleArr[i]) != ans.end()){
                while(!temp.empty()){
                    ans.insert(temp.back());
                    temp.pop_back();
                }
            }
        }
        if(!temp.empty() && temp.back() == ind) temp.pop_back();
        visited[ind] = 1;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        set<int> ans;
        vector<int> temp;
        vector<int> visited(graph.size(),0);
        for(int i=0; i<graph.size(); i++){
            dfs(i, graph,visited, temp, ans) ;
        }
        vector<int> ans_c;
        for(int i=0; i<graph.size(); i++){
           
           if(ans.find(i) == ans.end())  ans_c.push_back(i);
        }
        return ans_c;
    }
};