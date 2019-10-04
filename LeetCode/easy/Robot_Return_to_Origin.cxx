class Solution {
public:
    bool judgeCircle(string moves) {
        int h = 0, v = 0;
        for (auto& c : moves)
        {
            if (c == 'L')
                --h;
            else if (c == 'D')
                ++v;
            else if (c == 'R')
                ++h;
            else if (c == 'U')
                --v;
        }
        return h == 0 && v == 0;
    }
};