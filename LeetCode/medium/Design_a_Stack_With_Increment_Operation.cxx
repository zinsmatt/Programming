class CustomStack {
    vector<int> data;
    int head;
public:
    CustomStack(int maxSize) : head(0) {
        data.resize(maxSize);
    }
    
    void push(int x) {
        if (head < data.size()) {
            data[head++] = x;
        }
    }
    
    int pop() {
        if (head == 0) return -1;
        --head;
        return data[head];
        
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < head && i < k; ++i) {
            data[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
