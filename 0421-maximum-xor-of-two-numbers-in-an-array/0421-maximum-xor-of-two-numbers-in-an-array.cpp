#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* links[2]; // Stores binary 0 or 1

    bool contains(int bit) {
        return links[bit] != NULL;
    }

    void put(int bit, TrieNode* node) {
        links[bit] = node;
    }

    TrieNode* get(int bit) {
        return links[bit];
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) { // Iterate from MSB to LSB
            int bit = (num >> i) & 1;
            if (!node->contains(bit)) {
                node->put(bit, new TrieNode());
            }
            node = node->get(bit);
        }
    }

    int getMaxXOR(int num) {
        TrieNode* node = root;
        int maxXor = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->contains(1 - bit)) { // Try to take opposite bit
                maxXor |= (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxXor;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for (int num : nums) {
            trie.insert(num);
        }

        int maxXor = 0;
        for (int num : nums) {
            maxXor = max(maxXor, trie.getMaxXOR(num));
        }
        return maxXor;
    }
};
