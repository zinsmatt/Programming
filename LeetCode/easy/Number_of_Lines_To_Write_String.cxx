class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        vector<int> res;
        int l = 0;
        int w = 0;
        int prev_w = 0;
        for (auto& c : S)
        {
            prev_w = w;
            auto li = widths[c - 'a'];
            if (w + li > 100)
            {
                w = li;
                ++l;
            }
            else
                w += li;
        }
        if (w == 0)
            return {l, prev_w};
        else
            return {l+1, w};
    }
};