class MyHashSet {
    int tab[1000001];
public:
    MyHashSet() {
        fill(tab, tab + 1000001, 0);
    }
    
    void add(int key) {
        tab[key] = 1;
    }
    
    void remove(int key) {
        tab[key] = 0;        
    }
    
    bool contains(int key) {
        return tab[key] == 1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
