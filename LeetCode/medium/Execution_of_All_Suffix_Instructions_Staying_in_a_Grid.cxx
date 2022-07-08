class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> res;
        for (int i = 0; i < s.size(); ++i) {
            int x = startPos[1];
            int y = startPos[0];
            int r = 0;
            int k = i;
            do {
                if (s[k] == 'U') y--;
                if (s[k] == 'D') y++;
                if (s[k] == 'L') x--;
                if (s[k] == 'R') ++x;
                if (x < 0 || y < 0 || x >= n || y >= n) break;
                ++k;
                ++r;
            } while (k < s.size());
            res.push_back(r);
        }
        return res;
    }
};
