struct Node
{
    bool end;
    Node* next[26];
    Node(): end(false) {
        for (int i = 0; i < 26; ++i)
        {
            next[i] = nullptr;
        }
    } 
};


void add(const string& s, Node* n, int i)
{
    if (i >= s.size())
        return;
    if (n->next[s[i]-'a'] == nullptr)
    {
        n->next[s[i]-'a'] = new Node();
    }
    if (i == s.size()-1)
    {
        n->next[s[i]-'a']->end = true;
    }
    else  
        add(s, n->next[s[i]-'a'], i+1);
}


Node* find(const string& s, Node *n, int i)
{
    if (i >= s.size())
        return n;
    if (n->next[s[i]-'a'] == nullptr)
        return nullptr;
    else
        return find(s, n->next[s[i]-'a'], i+1);
}

class Trie {
    Node* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if (!search(word))
        {
            add(word, root, 0);
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto* ret = find(word, root, 0);
        if (!ret)
            return false;
        else
            return ret->end;
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix, root, 0) != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
