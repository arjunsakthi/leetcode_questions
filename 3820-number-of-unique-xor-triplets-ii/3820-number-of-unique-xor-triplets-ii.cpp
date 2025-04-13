class Solution {
public:
    int uniqueXorTriplets(vector<int>& a) {
        unordered_set<int> st, s;
        int n = a.size();
        if(n==1 || n==2) return n;

        for(int i=0; i<n-1; i++){
            for(int j = i+1; j<n; j++){
                st.insert(a[i]^a[j]);
            }
        }

        for(auto num: st){
            for(auto x: a){              
                s.insert(num^x);          
            }
        }
        return s.size();
    }
};