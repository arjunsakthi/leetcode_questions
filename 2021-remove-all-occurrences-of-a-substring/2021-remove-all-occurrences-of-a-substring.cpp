class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part) != string::npos){
            int k = s.find(part);
            s.erase(k,part.size());
        }
        return s;
    }
};