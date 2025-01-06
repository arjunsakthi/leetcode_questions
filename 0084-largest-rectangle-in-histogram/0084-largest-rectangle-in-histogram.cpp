class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> preSmaller(heights.size());
        vector<int> nextSmaller(heights.size());
        stack<int> st;
        for(int i=0; i<heights.size();i++){
            if(st.empty())  preSmaller[i] = -1;
            else{
                while(!st.empty() && heights[st.top()] >= heights[i]){
                    st.pop();
                }
                if(st.empty())  preSmaller[i] = -1;
                else{
                    preSmaller[i] = st.top();
                }
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
         for(int i=heights.size()-1; i>=0;i--){
            if(st.empty())  nextSmaller[i] = heights.size();
            else{
                while(!st.empty() && heights[st.top()] >= heights[i]){
                    st.pop();
                }
                if(st.empty())  nextSmaller[i] = heights.size();
                else{
                    nextSmaller[i] = st.top();
                }
            }
            st.push(i);
        }
        int maxi = 0;
        for(int i=0; i<heights.size(); i++){
            maxi = max(maxi, (nextSmaller[i] - preSmaller[i] - 1)*heights[i]);
        }
        return maxi;
    }
};