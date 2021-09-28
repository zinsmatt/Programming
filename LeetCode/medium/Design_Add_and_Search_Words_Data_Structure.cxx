class WordDictionary {
    
    struct Node
    {
        bool end;
        std::array<Node*, 26> next;
        Node() {
            for (int i = 0; i < next.size(); ++i)
                next[i] = nullptr;
            end = false;
        }
    };
    
    Node* head;
    
public:
    WordDictionary() {
        head = new Node();
    }
    
    void addWord(string word) {
        auto *p = head;
        int i = 0;
        while (i < word.size())
        {
            auto c = word[i];
            if (p->next[c-'a'])
                p = p->next[c-'a'];
            else
                break;
            ++i;               
        }
        while (i < word.size())
        {
            auto c = word[i];
            p->next[c-'a'] = new Node();
            p = p->next[c-'a'];
            ++i;
        }
        p->end = true;
    }
    
    bool recursive_search(const std::string& word, int i, Node* cur)
    {
        if (!cur) return false;
        if (i >= word.size()) return cur->end;
        else if (word[i] == '.')
        {
            bool res = false;
            for (auto n : cur->next)
            {
                res |= recursive_search(word, i+1, n);
            }
            return res;
        }
        else if (cur->next[word[i]-'a'] != nullptr)
        {
            return recursive_search(word, i+1, cur->next[word[i]-'a']);
        }
        else
        {
            return false;
        }
    }
    
    bool search(string word) {
        return recursive_search(word, 0, head);        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
