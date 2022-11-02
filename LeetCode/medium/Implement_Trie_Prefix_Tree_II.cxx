struct Node
{
    Node* children[26];
    bool end;
    
    Node() {
        std::fill(children, children+26, nullptr);
        end = false;
    }
    
    void set_end(bool s) {
        end = s;
    }
    
    bool is_end() {
        return end;
    }

};

class Trie {
    Node* root;

public:
    Trie() {
        root = new Node;
        root->set_end(true);        
    }
    
    void insert(string word) {
        Node* pt = root;
        for (auto c : word) {
            if (pt->children[c-'a']) {
                pt = pt->children[c-'a'];
            } else {
                pt->children[c-'a'] = new Node;
                pt = pt->children[c-'a'];
            }
        }
        pt->set_end(true);
    }
    
    bool search(string word) {
        Node* pt = root;
        for (auto c : word) {
            if (pt->children[c-'a']) {
                pt = pt->children[c-'a'];
            } else {
                return false;
            }
        }
        return pt->is_end();
    }
    
    bool startsWith(string prefix) {
        Node* pt = root;
        for (auto c : prefix) {
            if (pt->children[c-'a']) {
                pt = pt->children[c-'a'];
            } else {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
