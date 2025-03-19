class Solution {
public:
    vector<int> parent, size;

    int pUltimate(int ele) {
        return parent[ele] = (ele == parent[ele] ? ele : pUltimate(parent[ele]));
    }

    void Union(int ele1, int ele2) {
        int par1 = pUltimate(ele1);
        int par2 = pUltimate(ele2);
        if (par1 == par2) return;
        if (size[par1] > size[par2]) {
            size[par1] += size[par2];
            parent[par2] = par1;
        } else {
            size[par2] += size[par1];
            parent[par1] = par2;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0, maxCol = 0;
        for (auto& it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        int n = maxRow + maxCol + 2; // To accommodate row and column nodes
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) parent[i] = i; // Initialize parent

        // unordered_map<int, int> stoneNodes;
        set<int> st;
        for (auto& it : stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1; 
            Union(nodeRow, nodeCol);
            // stoneNodes[nodeRow] = 1;
            // stoneNodes[nodeCol] = 1;
        }
         for (auto& it : stones) {
            st.insert(pUltimate(it[0]));
        }
        int cnt = st.size();
        // int cnt = 0;
        // for (auto& it : stoneNodes) {
        //     if (pUltimate(it.first) == it.first) {
        //         cnt++;
        //     }
        // }

        return stones.size() - cnt;
    }
};
