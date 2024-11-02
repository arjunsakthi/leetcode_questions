class Solution {
public:
    bool isCircularSentence(string sentence) {
        for(int i=0; i<sentence.size(); i++){
            if(sentence[i] == ' '){
                if(sentence[i-1] != sentence[i+1])  return false;
            }
        }
        if(sentence[sentence.size()-1] != sentence[0])  return false;
        return true;
    }
};