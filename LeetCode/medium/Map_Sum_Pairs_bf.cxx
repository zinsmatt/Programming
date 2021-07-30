class MapSum {
    std::unordered_map<string, int> m;
public:
    
    bool pref(const string& s, const string& p)
    {
        return s.substr(0, p.size()) == p;
    }


    /** Initialize your data structure here. */
    MapSum() {
        
        
    }
    
    void insert(string key, int val) {
        m[key] = val;
    }
    
    int sum(string prefix) {
        int s = 0;
        for (auto it : this->m)
        {
            if (pref(it.first, prefix))
            {
                s += it.second;
            }
        }
        return s;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
