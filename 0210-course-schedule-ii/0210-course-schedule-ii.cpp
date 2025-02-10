class Solution {
public:
    bool dfs(vector<vector<int>> &adj,vector<int> &visited,vector<int> &pathVisited, int ind, vector<int> &ans){
        visited[ind] = 1;
        pathVisited[ind] = 1;
        vector<int> k = adj[ind];
        for(int i=0; i<k.size(); i++){
            if(!visited[k[i]]){
                if(dfs(adj, visited, pathVisited, k[i],ans))    return true;
            }
            else if(pathVisited[k[i]]){
                return true;
            }
        }
        ans.push_back(ind);
        pathVisited[ind] = 0;
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> visited(numCourses,0);  
        vector<int> pathVisited(numCourses,0);  
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> ans;
        for(int i=0; i<numCourses; i++){
            if(!visited[i] && dfs(adj, visited, pathVisited, i, ans))  return {};
        }
        return ans;

    }
};