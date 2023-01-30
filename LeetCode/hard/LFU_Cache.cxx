struct Item
{
    int key;
    int freq;
    int time;

    bool operator <(const Item& b) {
        if (freq == b.freq)
            return time < b.time;
        else 
            return freq < b.freq;
    }
};


class LFUCache {
    std::vector<Item> v;
    int capa;
    int count = 0;
    int it = 0;
    unordered_map<int, pair<int, int>> m;

public:
    LFUCache(int capacity) : capa(capacity) {
        v.resize(capacity);
    }


    void heapify_up(int idx) {
        if (idx == 0)
            return ;
        
        int parent_idx = idx / 2;
        if (v[idx] < v[parent_idx]) {
            // swap indices in m
            swap(m[v[parent_idx].key].second, m[v[idx].key].second);
            swap(v[parent_idx], v[idx]);

            heapify_up(parent_idx);
        }
    }

    void heapify_down(int idx) {
        if (idx >= count)
            return ;
        int idx_l = idx*2+1;
        int idx_r = idx*2+2;

        if (idx_r < count) {
            // both
            int min_idx = idx_l;
            if (v[idx_r] < v[idx_l]) {
                min_idx = idx_r;
            }

            if (v[min_idx] < v[idx]) {
                // update index in m
                swap(m[v[idx].key].second, m[v[min_idx].key].second);
                swap(v[idx], v[min_idx]);

                heapify_down(min_idx);
            }
        } else if (idx_l < count) {
            // only left
            if (v[idx_l] < v[idx]) {
                // update index in m
                swap(m[v[idx].key].second, m[v[idx_l].key].second);
                swap(v[idx], v[idx_l]);

                heapify_down(idx_l);
            }
        }
    }




    
    int get(int key) {
        if (capa == 0)
            return -1;

        if (m.count(key) == 0) {
            return -1;
        }

        auto val = m[key].first;
        auto idx = m[key].second;

        v[idx].freq++;
        v[idx].time = it;
        heapify_down(idx);
        
        ++it;
        return val;
    }

    
    void put(int key, int value) {
        if (capa == 0)
            return ;

        list<int>::iterator pt;
        if (m.count(key) == 0) {
            // no yet inside
            Item nouv({key, 1, it});
            if (count == capa) {
                // no more place
                m.erase(v[0].key);
                v[0] = nouv;
                m[key] = {value, 0};
                heapify_down(0);
            } else {
                int idx = count;
                v[idx] = nouv;
                m[key] = {value, idx};
                ++count;
                heapify_up(idx);
            }
        } else {
            m[key].first = value;
            auto idx = m[key].second;
            v[idx].freq++;
            v[idx].time = it;
            heapify_down(idx);
        }

        ++it;
    }

    void print() {
        for (int i = 0; i < count; ++i)
        cout << "(" << v[i].key << ", " << v[i].freq << ", " << v[i].time << ") ";
        cout << "\n";
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
