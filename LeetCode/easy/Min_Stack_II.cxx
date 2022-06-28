

class MinStack {
	stack<int> s;
	stack<int> smin;
public:
    MinStack() {
        
    }
    
    void push(int val) {
s.push(val);
if (smin.size() == 0)
	smin.push(val);
else
	smin.push(min(val, smin.top()));
    }
    
    void pop() {
s.pop();
	smin.pop();
    }
    
    int top() {
        	return s.top();
    }
    
    int getMin() {
        return smin.top();
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

