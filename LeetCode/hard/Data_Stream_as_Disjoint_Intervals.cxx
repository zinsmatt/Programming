class SummaryRanges {
    vector<int> parents;
    vector<int> counts;

    int find(int x) {
        if (parents[x] == -1)
            return x;
        else
            return find(parents[x]);
    }

    void f_union(int a, int b) {
        auto ra = find(a);
        auto rb = find(b);
        if (ra != rb) {
            parents[rb] = ra;
            counts[ra] += counts[rb];
            counts[rb] = 0;
        }
    }

public:
    SummaryRanges() {
        parents.resize(10001, -1);
        counts.resize(10001, 0);
    }
    
    void addNum(int value) {
        if (counts[find(value)])
            return;
        counts[value]++;
        if (value > 0 && counts[find(value-1)]) {
            f_union(value-1, value);
        }
        if (value < parents.size()-1 && counts[find(value+1)]) {
            f_union(value, value+1);
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (int i = 0; i < counts.size(); ++i) {
            if (counts[i]) {
                res.push_back({i, i+counts[i]-1});
            }
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
