class FirstUnique {
    
    unordered_map<int, pair<int, list<int>::iterator>> m;
    list<int> q;
    
public:
    FirstUnique(vector<int>& nums) {
        for (auto x : nums)
            add(x);
    }
    
    int showFirstUnique() {
        if (q.size() == 0)
            return -1;
        else
            return q.front();
    }
    
    void add(int value) {
        auto it = m.find(value);
        if (it == m.end())
        {
            q.push_back(value);
            m[value] = {1, --q.end()};
        }
        else
        {
            if (m[value].first)
            {
                q.erase(m[value].second);
                m[value].first = 0;
            }
        }   
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
