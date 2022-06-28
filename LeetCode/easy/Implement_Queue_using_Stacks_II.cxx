
class MyQueue {
 std::stack<int> a, b;
public:
    MyQueue() {
    }
    
    void push(int x) {
        a.push(x);
    }

    void reverse() {
while (a.size()) {
b.push(a.top());
a.pop();
}
    }
    
    int pop() {
    	if (empty()) 
return -1;
if (b.size() == 0)
reverse();
int x = b.top();
b.pop();        
return x;    
    }
    
    int peek() {
if (empty())
		return -1;
if (b.size() == 0)
        	reverse();
return b.top();
    }
    
    bool empty() {
    	return a.empty() && b.empty();        
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

