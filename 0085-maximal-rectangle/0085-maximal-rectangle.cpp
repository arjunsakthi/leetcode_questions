class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> prefixSum(matrix.size(),
                                      vector<int>(matrix[0].size()));
        for (int i = 0; i < matrix[0].size(); i++) {
            int count = 0;
            for (int j = 0; j < matrix.size(); j++) {
             if (matrix[j][i] == '1')
                    count++;
                else
                    count = 0;
                prefixSum[j][i] = count;
          }
            cout << endl;
        }
        int maxi = 0;
        for (int i = 0; i < matrix.size(); i++) {
            vector<int> heights = prefixSum[i];
            int localMaxi = 0;
            stack<int> st; // storing smaller index only
            for (int i = 0; i < heights.size(); i++) {
                if (st.empty()) {
                    st.push(i);
                } else {
                    while (!st.empty() && heights[st.top()] >= heights[i]) {
                        int top = st.top();
                        st.pop();
                        if (!st.empty()) {
                            localMaxi =
                                max(localMaxi, (i - st.top() -1) * heights[top]);
                        } else {
                            localMaxi =
                                max(localMaxi, (i - (-1) -1) * heights[top]);
                        }
                    }
                    st.push(i);
                }
            }
            while (!st.empty()) {
                int top = st.top();
                st.pop();
                if (!st.empty()) {
                    localMaxi = max(localMaxi, (int)(heights.size() - st.top() - 1) * heights[top]);
                } else {
                    localMaxi = max(localMaxi, (int)(heights.size() - (-1) - 1) * heights[top]);
                }
            }
            maxi = max(maxi, localMaxi);
        }
        return maxi;
    }
};