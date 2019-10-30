class Solution {
public:
    vector<int> partitionLabels(string S) {
        if (S.size() == 1)
            return {1};
        vector<pair<int, int>> occ(26, pair<int, int>(999, -1));
        for (int i = 0; i < S.size(); ++i)
        {
            if (i < occ[S[i] - 'a'].first)
                occ[S[i] - 'a'].first = i;
            if (i > occ[S[i] - 'a'].second)
                occ[S[i] - 'a'].second = i;
        }
        
        vector<int> res;
        int cur = 0;
        while (cur < S.size())
        {
            int i = cur;
            int cur_max = occ[S[i] - 'a'].second;
            while (i < cur_max)
            {
                cur_max = max(occ[S[i] - 'a'].second, cur_max);
                ++i;            
            }
            
            res.push_back(i - cur + 1);
            cur = i + 1;
        }
        return res;
    }
};