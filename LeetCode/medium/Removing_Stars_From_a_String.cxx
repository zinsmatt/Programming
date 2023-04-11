class Solution {
public:
    string removeStars(string s) {
        stringstream res;
        int n = 0;
        for (int i = s.size()-1; i >= 0; --i) {
            if (s[i] == '*') {
                n++;
            } else if (n == 0){
                res << s[i];
            } else {
                n = max(0, n-1);
            }
        }
        string r = res.str();
        reverse(r.begin(), r.end());
        return r;
    }
};
