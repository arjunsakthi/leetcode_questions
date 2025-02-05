class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.size() != s2.size())  return false;
        vector<int> ind;
        for(int i=0; i<s1.size(); i++){
            if(s1[i] != s2[i]){
                ind.push_back(i);
            }
        }
        if(ind.size() == 0) return true;
        if(ind.size() != 2 && ind.size() != 0){
            return false;
        }
        else{
            int r1 = ind.back();
            ind.pop_back();
            int r2 = ind.back();
            ind.pop_back();
            swap(s1[r1],s1[r2]);
            if(s1 != s2)    return false;
            else    return true;
        }
    }
};