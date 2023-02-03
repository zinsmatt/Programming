class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> g(numRows, string(s.size(), ' '));
        int r = 0;
        int k = 0;
        while (k < s.size()) {
            for (int i = 0; i < numRows && k < s.size(); ++i) {
                g[i][r] = s[k++];
            }
            if (k >= s.size())
                break;
            
            ++r;
            for (int t = 1; t < numRows-1 && k < s.size(); ++t) {
                g[numRows-1-t][r++] = s[k++];
            }
        }

        stringstream ss;
        for (auto &st : g) {
            for (int i = 0; i <= r && i < st.size(); ++i) {
                if (st[i] != ' ')
                    ss << st[i];
            }
        }
        return ss.str();
        
    }
};
