class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> counts(26, 0);
        bool first = true;
        for (auto const& w : A)
        {
            vector<int> occ(26, 0);
            for (auto& c : w)
                ++occ[c - 'a'];
            if (first)
            {
                first = false;
                counts = occ;
            }
            else
            {
                std::transform(counts.begin(), counts.end(), occ.begin(), counts.begin(), [](int a, int b) {
                    return min(a, b);
                });
            }
        }
        vector<string> res;
        for (int c = 0; c < counts.size(); ++c)
        {
            stringstream ss;
            ss << (char)('a'+c);
            for (int i = 0; i < counts[c]; ++i)
            {
                res.push_back(ss.str());
            }
        }
        return res;
    }
};