class MyHashSet {
    
    struct Node {
        int val;
        Node *left, *right;
        Node(int x) : val(x), left(nullptr), right(nullptr) {}
    };
public:
    Node* root;
    
    void inorder(Node *n) {
        if (n) {
            inorder(n->left);
            std::cout << " "  << n->val;
            inorder(n->right);
        } else 
            std::cout << " nullptr";
    }
    
    pair<Node*, Node*> find(int key) {
        // std::cout << "inorder: ";
        // inorder(root);
        // std::cout << "\n";
        Node* pt = root;
        Node *prev = nullptr;
        while (pt && pt->val != key) {
            prev = pt;
            if (pt->val < key)
                pt = pt->right;
            else
                pt = pt->left;
        }
        return {pt, prev};
    }
    
    MyHashSet() {
        root = nullptr;
    }
    
    void add(int key) {
        if (root == nullptr)
            root = new Node(key);
        else {
            auto [pt, prev] = find(key);
            if (pt != nullptr)
                return;
            if (prev->val < key) {
                prev->right = new Node(key);
            } else {
                prev->left = new Node(key);
            }
        }
    }
    
    void remove(int key) {
        auto [pt, prev] = find(key);

        if (pt == nullptr)
            return;

        if (pt->left == nullptr && pt->right == nullptr) {
            if (pt == root) // if found at root               
                root = nullptr;
            else if (prev->left == pt)
                prev->left = nullptr;
            else
                prev->right = nullptr;
            delete pt;
        } else if (pt->left == nullptr || pt->right == nullptr) {
            Node *child = pt->left ? pt->left : pt->right;
            if (pt == root) // if found at root
                root = child;
            else if (prev->left == pt)
                prev->left = child;
            else
                prev->right = child;
            delete pt;
        } else {
            // find successor
            Node *succ = pt->right;
            while (succ->left)
                succ = succ->left;
            int val = succ->val;
            remove(val);
            
            pt->val = val;
        }        
    }
    
    bool contains(int key) {
        auto [pt, prev] = find(key);
        return pt != nullptr; 
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
