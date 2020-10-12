class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        list<int> l;
        for (int i = 1; i <= m; ++i)
        {
            l.push_back(i);
        }
        
        vector<int> res;
        for (auto q : queries)
        {
            int i = 0;
            auto it = l.begin();
            while (*it != q)
            {
                ++i;
                ++it;
            }
            res.push_back(i);
            l.erase(it);
            l.push_front(q);
        }
        return res;
    }
};
