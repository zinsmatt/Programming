class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> pos;
        for (int i = 0; i < S.size(); ++i)
        {
            if (S[i] == C)
                pos.push_back(i);
        }
        vector<int> res;
        for (int i = 0; i < S.size(); ++i)
        {
            int v = S.size();
            for (auto p : pos)
            {
                v = min(v, abs(p-i));
            }
            res.push_back(v);
        }
        return res;
    }
};