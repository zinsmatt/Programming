class Solution {
    vector<int> equiv;

    int find(int a) {
        if (equiv[a] == -1)
            return a;
        else
            return find(equiv[a]);
    }

    void funion(int a, int b) {
        auto ra = find(a);
        auto rb = find(b);
        if (ra != rb) {
            if (ra < rb) {
                equiv[rb] = ra;
            } else {
                equiv[ra] = rb;
            }
        }
    }

public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        equiv.resize(26, -1);

        for (int i = 0; i < s1.size(); ++i) {
            funion(s1[i]-'a', s2[i]-'a');
        }
        string res = baseStr;
        for (int i = 0; i < res.size(); ++i) {
            res[i] = 'a'+find(baseStr[i]-'a');
        }

        return res;
    }
};
