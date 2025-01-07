#include <vector>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> pq; // Max-heap to track maximum value
        map<int, int> freqMap; // Frequency map for sliding window
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            // Add current element to priority queue and frequency map
            pq.push(nums[i]);
            freqMap[nums[i]]++;

            // Remove elements that are outside the current sliding window
            if (i >= k) {
                int outElem = nums[i - k]; // Element going out of the window
                freqMap[outElem]--;
                // if (freqMap[outElem] == 0) {
                //     freqMap.erase(outElem); // Remove if frequency becomes 0
                // }
            }

            // Clean up the heap's top elements that are not valid (i.e., not in the current window)
            while (!pq.empty() && freqMap[pq.top()] == 0) {
                pq.pop();
            }

            // Add the current maximum to the result (once the window size >= k)
            if (i >= k - 1) {
                result.push_back(pq.top());
            }
        }

        return result;
    }
};
