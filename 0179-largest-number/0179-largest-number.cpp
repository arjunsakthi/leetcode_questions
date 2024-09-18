class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> num;
        for(auto i:nums){
            num.push_back(to_string(i));
        }
        sort(num.begin(),num.end(),[](string &a,string &b){
            int s = min(a.size(),b.size());
            return (a+b<b+a);
        });
        string ans="";
        for(int i=num.size()-1;i>=0;i--) ans+=num[i];
        if(ans.size()==0)   return "";
        if(ans[0] == '0') return "0";
        return ans;
    }
};