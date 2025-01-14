class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> hashA(51,0);
        vector<int> hashB(51,0);
        vector<int> ans;
        for(int i=0; i<A.size(); i++){
            hashA[A[i]]++;
            hashB[B[i]]++;
            ans.push_back(count(hashA,hashB));
        }
        return ans;
    }
private :
    int count(vector<int>& hashA, vector<int>& hashB){
        int counts = 0;
        for(int i=0; i<51; i++){
            counts += hashA[i]&hashB[i];
        }
        return counts;
    }
};