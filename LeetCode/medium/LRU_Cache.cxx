class LRUCache {
    struct Node
    {
        int v;
        Node *prev = nullptr, *next = nullptr;
        Node(int x) : v(x) {}
    };
    
    struct List
    {
        Node *begin, *end;
        int size = 0;
        List() : begin(nullptr), end(nullptr) {}
        
        
        void print()
        {
            auto *p = begin;
            while (p) {
                cout << p->v << " ";
                p = p->next;
            }
            cout << "\n";
        }
        void append(int v)
        {
            auto* k = new Node(v);    
            if (end)
            {
                end->next = k;
                k->prev = end;
                end = k;
            }
            else
            {
                begin = k;
                end = k;
            }
            ++size;
        }
        
        void remove(Node* v)
        {
            if (!v || size == 0) return;
            if (size == 1)
            {
                delete begin;
                begin = nullptr;
                end = nullptr;
            }
            else
            {
                if (v == begin)
                {
                    begin = begin->next;
                    begin->prev = nullptr;
                    delete v;
                }
                else if (v == end)
                {
                    end = end->prev;
                    end->next = nullptr;
                    delete v;
                }
                else
                {
                    v->prev->next = v->next;
                    v->next->prev = v->prev;
                    delete v;
                }
            }
                        --size;

        }
    };

    unordered_map<int, pair<int, Node*>> m;
    List lru;    
    int capa;
public:
    LRUCache(int capacity) {
        capa = capacity;
    }
    
    int get(int key) {
        if (m.find(key) == m.end())
        {
            return -1;
        }
        else
        {           
            lru.remove(m[key].second);
            lru.append(key);      
            m[key].second = lru.end;


            return m[key].first;
        }
        
            
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end())
        {
            m[key].first = value;
            lru.remove(m[key].second);
            lru.append(key);
            m[key].second = lru.end;
        }
        else
        {
            if (lru.size == capa)
            {
                m.erase(lru.begin->v);
                lru.remove(lru.begin);
            }
            lru.append(key);
            m[key] = {value, lru.end};
        }
    }   
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
