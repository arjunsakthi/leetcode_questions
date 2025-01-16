class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
        map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        for(auto i: mp){
            pq.push({i.second, i.first});
        }
        vector<int> ans;
        for(int i=0; i<k; i++){
            if(pq.empty())  return {};
            pair<int,int> p = pq.top();
            pq.pop();
            ans.push_back(p.second);
        }
        return ans;
    }
};