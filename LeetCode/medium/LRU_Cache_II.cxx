

class LRUCache {
std::unordered_map<int, pair<int, std::list<int>::const_iterator>> m;
std::list<int> lru;
int max_capa;
    
public:
    LRUCache(int capacity) {
        max_capa = capacity;
    }
    
    void update_lru(int key) {
        // Update LRU
        lru.erase(m[key].second);
        lru.push_back(key);
        m[key].second = std::prev(lru.end());
    }
    
    int get(int key) {
        if (m.find(key) == m.end())
            return -1;

        update_lru(key);
        return m[key].first;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            m[key].first = value;
            update_lru(key);

	    } else {
            if (lru.size() == max_capa) {
                int to_remove = lru.front();
                lru.pop_front();
                m.erase(to_remove);
            }

            lru.push_back(key);
            m[key].first = value;
            m[key].second = std::prev(lru.end());
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


