class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int arr = times[targetFriend][0];
        priority_queue<int, vector<int>, greater<int> > g;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> h;
        int newchair = 0;

        sort(times.begin(),times.end());
        for(int i=0;times[i][0]<=arr; i++){
            int newarr = times[i][0];
            int newdep = times[i][1];
            while(h.size() != 0 && h.top()[0] <= newarr){
                int chair = h.top()[1];
                h.pop();
                g.push(chair);
            }
            if(arr == newarr)   return (g.size() != 0)? g.top() : newchair;
            if(g.size() == 0){
                h.push({newdep,newchair++});
            }else{
                int chair = g.top();
                h.push({newdep,chair});
                g.pop();
            }
        }
        return -1;
    }
};