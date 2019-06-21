class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        
        std::vector<std::vector<int>> found;
        
        std::stack<int> r;
        r.push(target);
        std::stack<std::vector<int>> path;
        path.push(std::vector<int>());
        while (r.size() > 0)
        {
            int reste = r.top();
            r.pop();
            auto p_init = path.top();
            path.pop();
            auto end = std::upper_bound(candidates.begin(), candidates.end(), reste);
            for (auto it = candidates.begin(); it != end; ++it)
            {
                auto p = p_init;
                p.push_back(*it);
                if (reste - *it == 0)
                {
                    found.push_back(p);
                }
                else
                {
                    r.push(reste - *it);
                    path.push(p);
                }
            }
            
        }
        
        std::set<std::vector<int>> ok;
        for (int i = 0; i < found.size(); ++i)
        {
            std::sort(found[i].begin(), found[i].end());
            ok.insert(found[i]);            
        }
        
        std::vector<std::vector<int>> ret;
        for (auto const& v : ok)
        {
            ret.push_back(v);
        }
        
        return ret;
    }
};