class Solution {
public:
    vector<int> parent, size;
    int pUltimate(int ele) {
        return parent[ele] = ele == parent[ele] ? ele : pUltimate(parent[ele]);
    }

    // union by size
    void Union(int ele1, int ele2) {
        
        int par1 = pUltimate(ele1);
        int par2 = pUltimate(ele2);
        cout << ele1 << " " << par1 << " " << ele2 << " " << par2 << endl;
        if(par1 == par2)    return ;
        if (size[par1] > size[par2]) {
            size[par1] += size[par2];
            parent[par2] = par1;
        } else {
            size[par2] += size[par1];
            parent[par1] = par2;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        parent.resize(isConnected.size());
        size.resize(isConnected.size(),1);
        vector<vector<int>> adj;
        for (int i = 0; i < isConnected.size(); i++) {
            parent[i]=i;
            for (int j = 0; j < isConnected[0].size(); j++) {
                if (i != j && isConnected[i][j]) {
                    adj.push_back({i,j});
                }
            }
        }
        for(auto &i : adj){
            Union(i[0],i[1]);
        }
        set<int> st;
        for(int i=0; i<isConnected.size(); i++){
            st.insert(pUltimate(i));
        }
        return st.size();
       
    }
};