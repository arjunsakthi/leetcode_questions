class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<pair<int,int>> required;
        int k=0;
        long long sum = 0;
        vector<int> marked(nums.size(),0);
        for(auto i : nums){
            pair<int,int> temp;
            temp.first = i;
            temp.second = k;
            required.push_back(temp);
            k++;
        }
        sort(required.begin(), required.end());
        for(auto i : required){
            int a = i.first;
            int b = i.second;
            if(marked[b] == 0){
                marked[b] = 1;
                marked[max(0,b-1)] = 1;
                marked[min((int)nums.size()-1,b+1)] = 1;
                sum += a;
            }
        }
        return sum;
    }
};