class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        std::unordered_map<int, std::unordered_set<int>> m;
        for (auto& v : logs) {
            if (!m.count(v[0])) {
                m[v[0]] = std::unordered_set<int>();
            }
            m[v[0]].insert(v[1]);
        }
        
        vector<int> count(k, 0);
        for (auto& t : m) {
            count[t.second.size()-1]++;
        }
        return count;
    }
};
