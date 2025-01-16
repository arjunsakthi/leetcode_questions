struct compare{
    bool operator()(pair<int,int> &p1, pair<int,int> &p2){
        return p1.first > p2.first;
    }
};


class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq1;
        vector<pair<int,int>> toInsert; 
        map<int,int> mpp;
        for(int i=0; i<hand.size(); i++){
            mpp[hand[i]]++;
        }
        for(auto i : mpp){
            pq1.push(make_pair(i.first, i.second));
        }
        while(!pq1.empty()){
            pair<int,int> pre = pq1.top();
            pq1.pop();
            if(pre.second != 1)  toInsert.push_back(make_pair(pre.first,pre.second - 1));
            for(int i=0; i<groupSize-1; i++){
                if(pq1.empty()) return false;
                pair<int,int> cur = pq1.top();
                pq1.pop();
                if(cur.first != pre.first + 1)  return false;
                else pre = cur;
                if(cur.second != 1)  toInsert.push_back(make_pair(cur.first,cur.second - 1));
            }
            while(toInsert.size() > 0){
                pq1.push(toInsert.back());
                toInsert.pop_back();
            }
        }
        return true;
    }
};