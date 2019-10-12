class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int x = label;
        vector<int> res;
        int h = static_cast<int>(std::log2(x));
        while (x > 1)
        {
            res.push_back(x);
            x = x / 2;
            --h;
            
            int l = std::pow(2, h);
            int r = std::pow(2, h+1) - 1;
            int v = x - l;
            x = r - v;
        }
        res.push_back(1);
        std::reverse(res.begin(), res.end());
        return res;
    }
};