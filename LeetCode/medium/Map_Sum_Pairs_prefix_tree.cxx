struct Node
{
    int val;
    int sum;
    array<Node*, 26> next;
    
    Node (int val, int sum) {
        this->val = val;
        this->sum = sum;        
        for (int i = 0; i < 26; ++i)
            next[i] = nullptr;
    }
};


class MapSum {
    Node* root;
    
    pair<Node*, int> find(const string s)
    {
        auto* p = root;
        for (int i = 0; i < s.size(); ++i)
        {
            char c = s[i];
            if (p->next[c-'a'])
            {
                p = p->next[c-'a'];
            }
            else
            {
                return {p, i};
            }
        }
        return {p, -1};
    }

    
    void disp(Node* n, string s)
    {
        if (n)
        {
            std::cout << s << " : " << n->val << " | " << n->sum << "\n";
            for (int i = 0; i < 26; ++i)
            {
                if (n->next[i])
                    disp(n->next[i], s + (char)('a' + i));
            }
        }
    }
    
    void debug()
    {
        disp(root, "");   
    }
    
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new Node(0, 0);
    }
    
    void insert(string key, int val) {
        auto [n, i] = find(key);
        if (i == -1)
        { // already exists
            
            auto d = val - n->val;
            
            // update prefixes
            auto* p = root;
            for (auto c : key)
            {
                p = p->next[c-'a'];
                p->sum += d;
            }
            p->val = val;
        }
        else
        { // new element
            
            auto* p = root;
            for (int j = 0; j < i; ++j)
            {
                p = p->next[key[j]-'a'];
                p->sum += val;
            }
            
            
            while (i < key.size())
            {
                p->next[key[i]-'a'] = new Node(0, val);
                p = p->next[key[i]-'a'];
                ++i;
            }
            p->val = val;
        }
    }
    
    
    int sum(string prefix) {
        //debug();
        auto [n, i] = find(prefix);
        if (i != -1) return 0;
        return n->sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
