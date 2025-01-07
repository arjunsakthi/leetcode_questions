class StockSpanner {
public:
    stack<int> st;
    vector<int> arr;
    StockSpanner() {
    }
    
    int next(int price) {
        int val = -1;
        arr.push_back(price);
        if(st.empty()){
            val = arr.size();
        }
        while(!st.empty() && arr[st.top()] <= price){
            st.pop();
        }
        if(!st.empty()){
            
            val = arr.size()-1-st.top();
        }
        else{
            val = arr.size();
        }
        st.push(arr.size()-1);
        return val;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */