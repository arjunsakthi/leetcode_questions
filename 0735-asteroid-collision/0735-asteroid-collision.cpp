class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int mainCount = 0;
        stack<int> st;
        vector<int> flag(asteroids.size(),0);
        for (int i = asteroids.size() - 1; i >= 0; i--) {
            if (asteroids[i] < 0)
                st.push(i);
            else {
                if (st.empty()) {
                    flag[i] = 1;
                } else {
                    while (!st.empty() && abs(asteroids[st.top()]) < asteroids[i]) {
                        st.pop();
                    }
                    if (!st.empty()) {
                        if (-asteroids[st.top()] == asteroids[i])
                            st.pop();
                    } else {
                        flag[i] = 1;
                    }
                }
            }
        }
        while(!st.empty()){
            flag[st.top()] = 1;
            st.pop();
        }
        vector<int> ans;
        for(int i=0; i<asteroids.size(); i++){
            if(flag[i]) ans.push_back(asteroids[i]);
        }
        return ans ;
    }
};