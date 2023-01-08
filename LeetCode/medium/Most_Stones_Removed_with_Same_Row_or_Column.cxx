class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        vector<vector<int>> rows(10001, vector<int>()), cols(10001, vector<int>());

        for (auto &s : stones) {
            rows[s[0]].push_back(s[1]);
            cols[s[1]].push_back(s[0]);
        }

        auto hash = [](int row, int col) {
            return row * 10001 + col;
        };

        int res = 0;
        unordered_map<int, int> done;
        for (auto& v : stones) {
            if (done.find(hash(v[0], v[1])) != done.end())
                continue;

            queue<pair<int, int>> q;
            q.push({v[0], v[1]});
            int count = 0;

            while (q.size()) {
                auto [i, j] = q.front();
                q.pop();

                for (auto e : rows[i]) {
                    int h = hash(i, e);
                    if (done.find(h) == done.end()){
                        done[h] = 1;
                        q.push({i, e});
                        ++count;
                    }
                }
                for (auto e : cols[j]) {
                    int h = hash(e, j);
                    if (done.find(h) == done.end()){
                        done[h] = 1;
                        q.push({e, j});
                        ++count;
                    }
                }
            }
            res += count - 1;
        }
        return res;
    }
};
