class MyQueue {
    std::stack<int> s_in, s_out;
    void reverse()
    {
        while (!s_in.empty())
        {
            s_out.push(s_in.top());
            s_in.pop();
        }        
    }
    
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s_in.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (s_out.empty())
            this->reverse();
        auto x = s_out.top();
        s_out.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        if (s_out.empty())
            this->reverse();
        return s_out.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s_in.empty() && s_out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
