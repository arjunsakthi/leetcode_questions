#include <vector>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq; // Max-heap: {value, index}
        map<int, int> freqMap; // To track frequency of elements in the current window
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            // Insert current element into the heap and frequency map
            pq.push({nums[i], i});
            freqMap[nums[i]]++;

            // Remove elements that are outside the current sliding window
            if (i >= k) {
                int outElem = nums[i - k]; // Element going out of the window
                freqMap[outElem]--;
                if (freqMap[outElem] == 0) {
                    freqMap.erase(outElem); // Remove if frequency becomes 0
                }
            }

            // Ensure the heap's top element is in the current window and valid
            while (!pq.empty() && (freqMap.find(pq.top().first) == freqMap.end() || pq.top().second <= i - k)) {
                pq.pop();
            }

            // Add the current maximum to the result (only when the window size >= k)
            if (i >= k - 1) {
                result.push_back(pq.top().first);
            }
        }

        return result;
    }
};
