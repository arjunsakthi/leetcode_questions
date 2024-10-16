class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        vector<pair<int, char>> nums = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
        sort(nums.rbegin(), nums.rend());
        char firstch = nums[0].second;
        int firstcnt = nums[0].first;
        char secondch = nums[1].second;
        int secondcnt = nums[1].first;
        char thirdch = nums[2].second;
        int thirdcnt = nums[2].first;
        string temp;
        while(firstcnt != 0 || secondcnt != 0 || thirdcnt != 0){
            if(firstcnt > secondcnt + thirdcnt){
                int cnt = 2;
                if(temp.size()>0 && temp.back() == firstch) break;
                while(cnt-->0 && firstcnt>0){
                    temp += firstch;
                    firstcnt--;
                }
                if(secondcnt > 0){
                    temp += secondch;
                    secondcnt--;
                }
                else if(thirdcnt > 0){
                    temp += thirdch;
                    thirdcnt--;
                }
            }
            else{
                if(firstcnt > 0){
                    temp += firstch;
                    firstcnt--;
                }
                if(secondcnt > 0){
                    temp += secondch;
                    secondcnt--;
                }
                if(thirdcnt > 0){
                    temp += thirdch;
                    thirdcnt--;
                }
            }
        }
        return temp;
    }
};