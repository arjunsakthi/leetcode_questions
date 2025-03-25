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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie trie;

        vector<pair<int,pair<int,int>>> qu;
        int maxXor = 0;
        for (int i=0; i<queries.size(); i++) {
            qu.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(nums.begin(),nums.end());
        sort(qu.begin(), qu.end());
 vector<int>ans(qu.size());
        int maxi = 0;
        int i=0;
        int j=0;
        while(i<qu.size()){
            maxi = qu[i].first;
            while(j < nums.size() && nums[j] <= maxi){
                trie.insert(nums[j]);
                j++;
            }
            if(j!=0)
            ans[qu[i].second.second] =trie.getMaxXOR(qu[i].second.first);
            else
            ans[qu[i].second.second] =-1;
            i++;
        }
       
        return ans;
    }
};