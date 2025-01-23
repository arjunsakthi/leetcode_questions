class Solution {
public:

    bool whetherPossible(map<int,int> &mp, int cost){
        for(auto it=mp.rbegin(); it != mp.rend(); it++){
            if(cost >= it->first && it->second != 0){
                while(cost >= it->first + 5 && it->second && cost > 5){
                    cost -= it->first;
                    mp[it->first]--;
                }
            }
        }
        cout << cost << endl;
        return cost == 5;
    }

    bool lemonadeChange(vector<int>& bills) {
        map<int,int> mp = {{5,0},{10,0},{20,0}};
        for(int i=0; i<bills.size(); i++){
            if(!whetherPossible(mp, bills[i])){
                return false;
            }
            mp[bills[i]]++;
        }
        return true;
    }
};