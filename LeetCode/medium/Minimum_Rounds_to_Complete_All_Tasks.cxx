class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        std::unordered_map<long, int> m;
        for (auto t : tasks) {
            if (m.find(t) == m.end()) {
                m[t] = 1;
            } else {
                m[t]++;
            }
        }

        long res = 0;
        for (auto it : m) {
            long x = it.second;
            if (x == 1)
                return -1;
            res += x/3;
            if (x % 3 != 0)
                res += 1;
            std::cout << x << " " << res << "\n";
        }
        return res;
    }
};
