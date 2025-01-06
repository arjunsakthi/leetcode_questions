class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<pair<int,int>> left(boxes.size(), {0,0});
        vector<pair<int,int>> right(boxes.size(), {0,0});
        left[0].first = boxes[0]-'0';
        for(int i=1; i<boxes.size(); i++){
            left[i].second = left[i-1].second + left[i-1].first;
            left[i].first = boxes[i]-'0' + left[i-1].first;
        }
        right[boxes.size()-1].first = boxes[boxes.size()-1] - '0';
        for(int i=boxes.size()-2; i>=0; i--){
            right[i].second = right[i+1].second + right[i+1].first;
            right[i].first = boxes[i]-'0' + right[i+1].first;
        }
        vector<int> ans(boxes.size(),0);
        for(int i=0; i<ans.size(); i++){
            ans[i] = left[i].second + right[i].second;
        }
        return ans;
    
    }
};