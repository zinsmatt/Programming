class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        std::set<int> s;
        for (auto& p : points) {
            s.insert(p[0]);
        }
        auto it = s.begin();
        auto it2 = it;
        it++;
        int res = 0;
        while (it != s.end())
        {
            res = std::max(res, *it-*it2);
            ++it2;
            ++it;
        }
        return res;
    }
};
