class Solution {
public:
    vector<int> diStringMatch(string S) {
        int I = 0, D = 0;
        for (auto& c : S)
        {
            if (c == 'I')
            {
                ++I;
            }
            else
                ++D;
        }
        
        int start = S.size() - I;
        int a = 0, b = 0;
        vector<int> res = {start};
        for (int i = 0; i < S.size(); ++i)
        {
            if (S[i] == 'I')
            {
                ++a;
                res.push_back(start+a);
            }
            else
            {
                ++b;
                res.push_back(start-b);
            }
        }
        return res;        
    }
};