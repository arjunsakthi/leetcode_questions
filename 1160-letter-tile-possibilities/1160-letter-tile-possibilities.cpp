class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector<int> visited(tiles.size(),0);
        sort(tiles.begin(), tiles.end());
        string temp="";
        int ind = 0;
        return rec(visited, tiles.size(), tiles);
        
    }
private:
    int rec(vector<int> &visited,int n, string &tiles){
        int count = 0;
        for(int i=0; i<n; i++){
            if(visited[i] || (i>0 && tiles[i] == tiles[i-1] && !visited[i-1]))   continue;
            if(!visited[i]){
                visited[i]=1;
                count+= 1+rec(visited, n, tiles);
                visited[i] = 0;
            }
        }
     
        return count;
    }
};