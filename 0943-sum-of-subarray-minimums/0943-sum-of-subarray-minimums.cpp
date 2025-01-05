class Solution {
public:
    int MOD = (int)(1e9+7);
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> pre(arr.size()), next(arr.size());
        stack<int> st;
        for(int i=0; i<arr.size(); i++){
            if(st.empty()){
                pre[i] = -1;
            }
            else{
                while(!st.empty() && arr[st.top()] > arr[i]){
                    st.pop();
                }
                if(!st.empty()){
                    pre[i] = st.top();
                }
                else{
                    pre[i] = -1;
                }
            }
            st.push(i);
        }
        while(!st.empty())  st.pop();
        for(int i=arr.size()-1; i>=0; i--){
            if(st.empty()){
                next[i] = arr.size();
            }
            else{
                while(!st.empty() && arr[st.top()] >= arr[i]){
                    st.pop();
                }
                if(!st.empty()){
                    next[i] = st.top();
                }
                else{
                    next[i] = arr.size();
                }
            }
            st.push(i);
        }
        int mainCount = 0;
        for(int i=0; i<arr.size(); i++){
            mainCount = (mainCount + ((i - pre[i])*1LL*(next[i] - i)*arr[i])%MOD)%MOD;
        }
        return mainCount;
    }
};