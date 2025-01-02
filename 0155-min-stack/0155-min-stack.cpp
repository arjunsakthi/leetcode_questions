class MinStack {
public:
    stack<int> *st;
    stack<int> *arr;
    MinStack() {
        st = new stack<int>;
        arr = new stack<int>;
    }
    
    void push(int val) {
        st->push(val);
        if(arr->size() == 0)    arr->push(val);
        else    arr->push(min(arr->top(),val));
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