#include <vector>
#include <algorithm>
#include <string>

class Solution {
public:
    int findTheLongestSubstring(const std::string& s) {
        // Vector to store the first occurrence of each bitmask
        std::vector<int> mapy(32, -2);
        mapy[0] = -1;

        int max_len = 0;
        int mask = 0;

        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            switch (ch) {
                case 'a':
                    mask ^= 1;
                    break;
                case 'e':
                    mask ^= 2;
                    break;
                case 'i':
                    mask ^= 4;
                    break;
                case 'o':
                    mask ^= 8;
                    break;
                case 'u':
                    mask ^= 16;
                    break;
            }

            int prev = mapy[mask];
            if (prev == -2) {
                mapy[mask] = i;
            } else {
                max_len = std::max(max_len, i - prev);
            }
        }

        return max_len;
    }
};
