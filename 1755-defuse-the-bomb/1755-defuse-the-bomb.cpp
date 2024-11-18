class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> nums(code.size(),0);
        if(k > 0){
            
            for(int i=0; i<code.size(); i++){
                for(int j=i+1; j<=i+k; j++){
                    nums[i] += code[j%code.size()];
                }
            }
        }
        else if(k<0){
            for(int i=0; i<code.size(); i++){
                for(int j=i-1; j>=i+k; j--){
                    nums[i] += code[(j+code.size())%code.size()];
                }
            }
        }
        return nums;
    }
};