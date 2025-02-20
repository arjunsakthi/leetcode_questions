class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        vector<int> numsInt(nums.size(),0);
        for(int i=0; i<nums.size(); i++){
            numsInt[i] = BinToInt(nums[i]);
        }
        sort(numsInt.begin(),numsInt.end());
        for(int i=0; i<nums.size(); i++){
            cout << i << " " << numsInt[i];
            if(i != numsInt[i]){
                return IntToBin(i, nums.size());
            }
        }
        return IntToBin(nums.size(), nums.size());

    }
    private:
    int BinToInt(string num){
        int k = 1;
        int ans = 0;
        int i = num.size() - 1;
        while(i >= 0){
            ans += k*(num[i]-'0');
            k*=2;
            i--;
        }
        return ans;
    }
    string IntToBin(int num,int n){
        string ans = "";
        while(num > 0){
            if(num&1)  ans.push_back('1');
            else ans.push_back('0');
            num /= 2;
        }
        while(ans.size() < n)ans.push_back('0');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};