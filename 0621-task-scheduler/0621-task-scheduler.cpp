class Solution {
    struct compare {
        bool operator()(pair<int, int>& p1, pair<int, int>& p2) {
            return p1.first < p2.first; // Max-heap behavior
        }
    };

public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int, int> mpp;
        for (char i : tasks) {
            mpp[i]++;
        }
        priority_queue<int> pq;
        for (auto i : mpp) {
            pq.push(i.second); // Push frequency and task
        }

        queue<pair<int, int>> cooldown; // {frequency, available time}
        int time = 0;

        while (!pq.empty() || !cooldown.empty()) {
            time++;

            // Add back tasks from cooldown if their time has arrived
            if (!cooldown.empty() && cooldown.front().second < time) {
                pq.push(cooldown.front().first);
                cooldown.pop();
            }

            // Process the most frequent task
            if (!pq.empty()) {
                int count = pq.top();
                pq.pop();
                count--; // Decrease the frequency
                if (count > 0) {
                    cooldown.push({count, time + n}); // Add to cooldown
                }
            }
        }

        return time;
    }
};
