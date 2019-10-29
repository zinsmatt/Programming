class MyCircularDeque {
public:
    vector<int> v;
    int front;
    int last;
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        v.resize(k);
        front = -1;
        last = -1;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (front == -1 && last == -1)
        {
            front = 0;
            last = 0;
            v[front] = value;
            return true;
        }
        auto tmp = (front + 1) % v.size();
        if (tmp == last)
            return false;
        v[tmp] = value;
        front = tmp; 
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (front == -1 && last == -1)
        {
            front = 0;
            last = 0;
            v[front] = value;
            return true;
        }
        auto tmp = last - 1;
        if (tmp < 0)
            tmp += v.size();
        if (tmp == front)
            return false;
        v[tmp] = value;
        last = tmp;        
        
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (front == -1 && last ==-1)
            return false;
        if (front == last)
        {
            front = -1;
            last = -1;
            return true;
        }
        --front;
        if (front < 0)
            front += v.size();
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (front == -1 && last == -1)
            return false;
        if (front == last)
        {
            front = -1;
            last = -1;
            return true;
        }
        last = (last + 1) % v.size();
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (front >= 0)
            return v[front];
        else 
            return -1;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (last >= 0)
            return v[last];
        else
            return -1;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return front == -1 && last == -1;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return (front + 1) % v.size() == last;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */