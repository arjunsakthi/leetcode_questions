// standard method n - n+1

// class Solution {
// public:
//     long long countOfSubstrings(string word, int k) {
//         return kvowel(word,k)-kvowel(word,k+1);
//     }
// private :
//     long long kvowel(string &word, int k){
//         long long sum=0;
//         int cons=0;
//         vector<int> vowel(26,0);
        
//         int l=0, r=0;
//         int n=word.size();
//         while(r<n){
//             vowel[word[r]-'a']++;
//             cons += !checkVowel(word[r]);
//             while(checkWind(vowel) && cons>=k){
//                 sum += n-r;
//                 vowel[word[l]-'a']--;
//                 cons -= !checkVowel(word[l]);
//                 l++;
//             }
//             r++;
//         } 
//         return sum;
//     }
//     bool checkVowel(char &c){
//         return (c=='a' || c=='e' || c=='i' || c=='o'|| c=='u');
//     }
//     bool checkWind(vector<int> &charWind){
//         return (charWind['a'-'a'] && charWind['e'-'a'] && charWind['i'-'a'] && charWind['o'-'a'] && charWind['u'-'a'] );
//     }
// };

// trying with precomputation

class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        long long sum=0;
        int cons=0;
        int n =word.size();
        vector<int> vowel(26,0);
        vector<int> nextC(n,n);
        int ind = n;
        for(int i=n-1; i>=0; i--){
            nextC[i] = ind;
            if(!checkVowel(word[i])){
                ind = i;
            }
        }
        int l=0, r=0;
        while(r<n){
            vowel[word[r]-'a']++;
            cons += !checkVowel(word[r]);
            while(checkWind(vowel) && cons>k){
                vowel[word[l]-'a']--;
                cons -= !checkVowel(word[l]);
                l++;
            }
            while(checkWind(vowel) && cons==k){
                sum += nextC[r]-r;
                vowel[word[l]-'a']--;
                cons -= !checkVowel(word[l]);
                l++;
            }
            
            r++;
        } 
        return sum;
    }
private :
    bool checkVowel(char &c){
        return (c=='a' || c=='e' || c=='i' || c=='o'|| c=='u');
    }
    bool checkWind(vector<int> &charWind){
        return (charWind['a'-'a'] && charWind['e'-'a'] && charWind['i'-'a'] && charWind['o'-'a'] && charWind['u'-'a'] );
    }
};
