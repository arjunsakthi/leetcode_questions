class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        map<int,int> mp;
        vector<int> nextGreater(nums.size());
        for(int i=nums.size()-2; i >= 0; i--){
            if(st.empty()){
                nextGreater[i] = -1;
            }
            else if(st.top() > nums[i]){
                nextGreater[i] = st.top();
            }
            else{
                while(!st.empty() && st.top() <= nums[i]){
                    st.pop();
                }
                if(!st.empty()){
                    nextGreater[i] = st.top();
                }else{
                   nextGreater[i] = -1;
                }
            }
            st.push(nums[i]);
        }
        for(int i=nums.size()-1; i >= 0; i--){
            if(st.empty()){
                nextGreater[i] = -1;
            }
            else if(st.top() > nums[i]){
                nextGreater[i] = st.top();
            }
            else{
                while(!st.empty() && st.top() <= nums[i]){
                    st.pop();
                }
                if(!st.empty()){
                    nextGreater[i] = st.top();
                }else{
                   nextGreater[i] = -1;
                }
            }
            st.push(nums[i]);
        }
        return nextGreater;
    }
};