class Solution {

    string stringify(vector<int>& v) {
        stringstream ss;
        for (auto x : v) {
            ss << setw(4) << std::setfill('0') << x;
        }
        return ss.str();
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<vector<int>> all;
        unordered_set<string> s;
        unordered_set<string> s_all;
        all.push_back({});
        s_all.insert("");
        for (auto x : nums) {
            vector<vector<int>> temp;
            for (auto v : all) {
                if (v.size() == 0 || v.back() <= x) {
                    v.push_back(x);

                    auto stv = stringify(v);
                    if (s_all.count(stv) != 0)
                        continue;
                    temp.push_back(v);

                    auto st = stringify(v);
                    if (v.size() >= 2 && s.count(st) == 0) {
                        s.insert(st);
                        res.push_back(v);
                    }
                }
            }
            all.insert(all.end(), temp.begin(), temp.end());
        }
        return res;        
    }
};
