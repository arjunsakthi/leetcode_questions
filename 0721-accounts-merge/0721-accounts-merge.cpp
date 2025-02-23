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

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        parent.resize(accounts.size());
        size.resize(accounts.size(),1);
        map<string,int> mp;
        for(int i=0; i<accounts.size(); i++){
            parent[i] = i;
            vector<string> ele = accounts[i];
            for(int j=1; j<ele.size(); j++){
                if(mp.count(ele[j])){
                    Union(i,mp[ele[j]]);
                }
                else{
                    mp[ele[j]]=i;
                }
            }
        }
        map<int,set<string>> temp;
        for(int i=0; i<accounts.size(); i++){
            int par = pUltimate(i);
            for(int j=1; j<accounts[i].size(); j++){
                temp[par].insert(accounts[i][j]);
            }
        }
        vector<vector<string>> ans;
        for(auto &it : temp){
            vector<string> temp;
            temp.push_back(accounts[it.first][0]);
            for(auto &itt : it.second){
                temp.push_back(itt);
            }
            ans.push_back(temp);
        }
        return ans;

    }
};