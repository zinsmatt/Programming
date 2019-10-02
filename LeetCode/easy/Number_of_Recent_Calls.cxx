class RecentCounter {
public:
    RecentCounter() {
        
        
    }
    
    int ping(int t) {
        q.push_back(t);
        ++b;
        if (q.size() == 1)
        {
            b = 0;
            a = 0;
        }
        
        // std::cout << "new " << t << "\n";
        while (a < q.size() && q[a] < t-3000)
        {
            ++a;
        }
        return b - a + 1;
    }
    int a = -1, b = -1;
    std::deque<int> q;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */