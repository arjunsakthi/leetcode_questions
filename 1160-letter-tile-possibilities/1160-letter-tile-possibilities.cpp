class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector<int> visited(tiles.size(),0);
        set<string> st;
        string temp="";
        int ind = 0;
        rec(ind, visited, st, temp, tiles.size(), tiles);
        return st.size()-1;
    }
private:
    void rec(int ind, vector<int> &visited, set<string> &st, string &temp,int n, string &tiles){
        if(ind == n)    {
            st.insert(temp);
            return;
        }
        for(int i=0; i<n; i++){
            if(!visited[i]){
                visited[i]=1;
                temp.push_back(tiles[i]);
                rec(ind+1, visited, st, temp, n, tiles);
                visited[i] = 0;
                temp.pop_back();
            }
        }
        rec(ind+1, visited, st, temp, n, tiles);
        return ;
    }
};