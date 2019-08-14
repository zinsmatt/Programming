class MinStack {
private:
    std::stack<int> q;
    std::stack<int> minq;
    
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        q.push(x);
        if (minq.empty() == false)
        {
            minq.push(std::min(x, minq.top()));
        }
        else
        {
            minq.push(x);
        }
    }
    
    void pop() {
        if (q.empty() == false)
        {
            q.pop();
            minq.pop();
        }
        
    }
    
    int top() {
        if (!q.empty())
            return q.top();
        else
            return -1;
    }
    
    int getMin() {
        if (minq.empty() == false)
            return minq.top();
        else
            return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */