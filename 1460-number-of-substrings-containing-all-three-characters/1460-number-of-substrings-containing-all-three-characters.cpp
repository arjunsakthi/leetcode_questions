class Solution {
public:
    int numberOfSubstrings(string s) {
        int total = (s.size()*(s.size()+1))/2;

        // checking all possible substring with window containing (negation of the question(atleast one char freq is 0 in the substring))
        vector<int> freq(3,0);
        int count = 0;
        int l=0;
        for(int i=0; i<s.size(); i++){
            freq[s[i]-'a']++;
            while(!check(freq)){
                freq[s[l]-'a']--;
                l++;
            }
            count += i-l+1;
        }
        return total - count;
    }
private:
    int check(vector<int> &freq){
        int flag = 0;
        for(int i=0; i<freq.size(); i++){
            if(freq[i] == 0)   {
                flag = 1;
                break;
            }
        }
        return flag;
    }
};