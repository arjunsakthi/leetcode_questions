class MinStack {
public:
    stack<int> *st;
    stack<int> *arr;
    MinStack() {
        st = new stack<int>;
        arr = new stack<int>;
        arr->push(INT_MAX);
    }
    
    void push(int val) {
        st->push(val);
        arr->push(min(arr->top(),val));
    }
    
    void pop() {
        st->pop();
        arr->pop();
    }
    
    int top() {
        return st->top();
    }
    
    int getMin() {
        return arr->top();
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