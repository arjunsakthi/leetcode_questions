class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
    int obtained = 0;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int i = 0; i < nums.size(); i++) {
            if (pq.size() < k) {
                pq.push(nums[i]);
            } else if (nums[i] > pq.top()) {
                pq.push(nums[i]);
                
                pq.pop();
            }

        }
        cout <<endl;
    }

    int add(int val) {
        if (pq.size() < this->k) {
            pq.push(val);

        } else if (val > pq.top()) {
            pq.push(val);
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */