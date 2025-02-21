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
        if(par1 == par2)    return ;
        if (size[par1] > size[par2]) {
            size[par1] += size[par2];
            parent[par2] = par1;
        } else {
            size[par2] += size[par1];
            parent[par1] = par2;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        parent.resize(stones.size());
        size.resize(stones.size(),1);
        map<int,vector<int>> row, col;
        for(int i=0; i<stones.size(); i++){
            parent[i] = i;
            row[stones[i][0]].push_back(i);
            col[stones[i][1]].push_back(i);
        }
        for(auto &rw : row){
            vector<int> r = rw.second;
            if(r.size() == 1)   continue;
            for(int i=1; i<r.size(); i++){
                Union(r[i-1],r[i]);
            }
        }
        for(auto &cl : col){
            vector<int> c = cl.second;
            if(c.size() == 1)   continue;
            for(int i=1; i<c.size(); i++){
                Union(c[i-1],c[i]);
            }
        }
        int count = 0;
        for(int i=0; i<stones.size(); i++){
            if(pUltimate(i) == i)   count++;
        }
        return stones.size()-count;
    }
};