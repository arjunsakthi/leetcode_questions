class Solution {
public:
    int minBitFlips(int start, int goal) {
        long long exor = start^goal;
        int count = 0;
        for(int i=0;i<32; i++){
            if(exor & 1<<i) count++;
        }
        return count;
    }
};