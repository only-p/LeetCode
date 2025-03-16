class MinStack {
public:
    stack<int> s, ms;
    // ms for min till now
    MinStack() {}

    void push(int val) {
        s.push(val);
        if (ms.size() == 0 || val <= ms.top()) {
            ms.push(val);
        }
    }

    void pop() {
        if (s.top() == ms.top()) {
            ms.pop();
        }
        s.pop();
    }

    int top() { return s.top(); }

    int getMin() { return ms.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */