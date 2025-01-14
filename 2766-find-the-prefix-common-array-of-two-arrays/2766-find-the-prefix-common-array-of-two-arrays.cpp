class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> hashA(51,0);
        vector<int> ans;
        int count = 0;
        for(int i=0; i<A.size(); i++){
            hashA[A[i]]++;
            if(hashA[A[i]] == 2)   count++;
            hashA[B[i]]++;
            if(hashA[B[i]] == 2)   count++;
            ans.push_back(count);
        }
        return ans;
    }
  
};