class MinStack {
public:
    stack<int> *st;
    vector<int> *arr;
    MinStack() {
        st = new stack<int>;
        arr = new vector<int>(30001,INT_MAX);
    }
    
    void push(int val) {
        st->push(val);
        (*arr)[st->size()] = min((*arr)[st->size()-1],val);
    }
    
    void pop() {
        st->pop();
    }
    
    int top() {
        return st->top();
    }
    
    int getMin() {
        return (*arr)[st->size()];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */