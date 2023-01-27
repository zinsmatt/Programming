class Solution {
    unordered_set<string> ss;
    bool is_concat(const std::string& w) {
        bool res = false;
        for (int i = w.size(); i >= 0; --i) {
            if (ss.count(w.substr(0, i))) {
                if (i == w.size())
                    return true;
                else
                    res |= is_concat(w.substr(i));
                    
                if (res)
                    return true;
            }
        }
        return res;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for (auto &w : words)
            ss.insert(w);
        
        vector<string> res;
        for (auto &w : words) {
            if (w.size() == 1)
                continue;
            ss.erase(w);
            if (is_concat(w))
                res.push_back(w);
            ss.insert(w);
        }
        return res;
    }
};
