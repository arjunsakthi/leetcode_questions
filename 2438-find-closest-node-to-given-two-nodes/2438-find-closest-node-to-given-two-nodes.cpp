class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> visited(edges.size() + 1, -1);
        // 1 for node1 visited
        // 2 for node2 visited
        queue<int> qu1, qu2;
        qu1.push(node1);
        qu2.push(node2);
        visited[node1] = 1;
        visited[node2] = 2;
        if (node1 == node2)
            return node1;

        while (!qu1.empty() || !qu2.empty()) {
            // node 1
            int n1 = -2, n2 = -2;
            if (!qu1.empty()) {
                int top = qu1.front();
                top = edges[top];
                qu1.pop();
                if (top != -1){
if (visited[top] == -1) {
                    visited[top] = 1;
                    qu1.push(top);
                } else if (visited[top] == 2) {
                    n1 = top;
                }
                }
                
            }
            if (!qu2.empty()) {
                int top = qu2.front();

                top = edges[top];
                qu2.pop();
                if (top != -1){
 if (visited[top] == -1) {
                    visited[top] = 2;
                    qu2.push(top);
                } else if (visited[top] == 1) {
                    n2 = top;
                }
                }
               
            }
            if (n1 != -2 && n2 != -2) {
                return min(n1, n2);
            }
            if (n1 != -2) {
                return n1;
            }
            if (n2 != -2) {
                return n2;
            }
        }
        return -1;
    }
};