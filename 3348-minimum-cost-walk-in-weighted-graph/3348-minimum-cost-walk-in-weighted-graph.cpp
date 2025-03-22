class Solution {
public:
    vector<int> par;
    vector<int> andd;
    vector<int> size;
    int Uparent(int node){
        if(node == par[node])   return node;
        return par[node] = Uparent(par[node]);
    }
    void Join(int node1, int node2, int edge){
        int p1 = Uparent(node1);
        int p2 = Uparent(node2);
        if(p1 == p2){
            andd[p1] &= edge;
            return;
        }
        else if(size[p1] >= size[p2]){
            size[p1] += size[p2];
            par[p2] = p1;
            andd[p1] &= andd[p2];
            andd[p1] &= edge;
        }
        else{
            size[p2] += size[p1];
            par[p1] = p2;
            andd[p2] &= andd[p1];
            andd[p2] &= edge;
        }
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        par.resize(n,0);
        size.resize(n,1);
        andd.resize(n,INT_MAX);
        vector<int> ans;
        for(int i=0; i<n; i++)  par[i]=i;
        for(int i=0; i<edges.size(); i++){
            int n1 = edges[i][0];
            int n2 = edges[i][1];
            int w = edges[i][2];
            Join(n1,n2,w);
        }
        for(int i=0; i<query.size(); i++){
            if(Uparent(query[i][0]) == Uparent(query[i][1])){
                ans.push_back(andd[Uparent(query[i][0])]);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};