class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        int ind = 0;
        vector<int> visited(n+1,0);
        vector<int> temp(2*n-1,0);
        rec(ind, visited, n, temp);
        return temp;
    }
private:
    bool rec(int ind, vector<int> &visited, int &n, vector<int> &temp){
       if(ind == 2*n-1) return true;
        if(temp[ind] != 0) 
                while (ind < 2*n-1 && temp[ind] != 0) ind++;
        if(ind == 2*n-1) return true;
              
        
        for(int i=n; i>=1; i--){
             if(i == 1 && visited[i] == 0){
                visited[i] = 1;
                temp[ind] = 1;
                if(rec(ind+1, visited, n, temp))  return true;
                visited[i] = 0;
                temp[ind] = 0;
            }
            else if(visited[i] == 0 && ind + i <= 2*n-2 && !temp[ind+i]){
                visited[i] = 1;
                temp[ind] = i;
                temp[ind + i] = i;
                if(rec(ind+1, visited, n, temp))  return true;
                visited[i] = 0;
                temp[ind] = 0;
                temp[ind + i] = 0;
            }
        }
        return false;
    }
};