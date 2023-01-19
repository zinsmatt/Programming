class RandomizedSet {
    unordered_map<int, int> m_;
    std::deque<int> d_;
    std::default_random_engine generator;

public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (m_.count(val))
            return false;
        m_[val] = d_.size();
        d_.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!m_.count(val))
            return false;
        int idx = m_[val];
        d_[idx] = d_.back();
        m_[d_.back()] = idx;
        m_.erase(val);
        d_.pop_back();
        return true;
    }
    
    int getRandom() {
        std::uniform_int_distribution<int> distribution(0, d_.size()-1);
        int idx = distribution(generator);
        return d_[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
