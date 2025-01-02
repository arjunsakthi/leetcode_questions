class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        st.push('.');
        for(auto i : s){
            if(i == '(' || i == '[' || i == '{'){
                st.push(i);
            }
            else if(i == ')' && st.top() == '(')    st.pop();
            else if(i == ']' && st.top() == '[')    st.pop();
            else if(i == '}' && st.top() == '{')    st.pop();
            else return false;
        }
        return st.size() == 1 ? true : false;
    }
};