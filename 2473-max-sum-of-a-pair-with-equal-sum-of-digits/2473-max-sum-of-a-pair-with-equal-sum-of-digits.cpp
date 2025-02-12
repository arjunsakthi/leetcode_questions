class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int,vector<int>> mp;
        
        for(auto i:nums){
            int sumDigit = sumOfDigit(i); 
            mp[sumDigit].push_back(i);
        }
        int maxi = -1;
        for(auto i : mp){
            int sum = i.first;
            vector<int> eles = i.second;
            if(eles.size() > 1){
                sort(eles.begin(), eles.end());
                maxi = max(maxi, eles[eles.size()-1]+eles[eles.size()-2]);
            }
           
        }
        return maxi;
    }
private:
    int sumOfDigit(int num){
        int sum = 0;
        cout << num << " ";
        while(num > 0){
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
};