class Solution {
public:
  vector<int> parent, size;
  int count = 0;
    int pUltimate(int ele) {
        return parent[ele] = ele == parent[ele] ? ele : pUltimate(parent[ele]);
    }

    // union by size
    void Union(int ele1, int ele2) {
        
        int par1 = pUltimate(ele1);
        int par2 = pUltimate(ele2);
        if(par1 == par2)   return ;
        count--;
        if (size[par1] > size[par2]) {
            size[par1] += size[par2];
            parent[par2] = par1;
        } else {
            size[par2] += size[par1];
            parent[par1] = par2;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1)  return -1;
         parent.resize(n);
        size.resize(n,1);
        count = n;
        for(int i=0; i<n; i++)
            parent[i] = i;
        
        for(int i=0; i<connections.size(); i++){
            Union(connections[i][0],connections[i][1]);
        }
        int req = 0;
        return count-1;
    }
};